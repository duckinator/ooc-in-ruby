#!/usr/bin/env ruby

require 'pp'

# void nq_setTokenPositionPointer(void *this, int *tokenPosPointer);

def func(ftype, fname, args)
  ftype.strip!
  fname.strip!
  args.map {|x| x.map(&:strip) }

  def_args = args.map do |x|
    if x.is_a?(Array)
      x.join(' ')
    else
      x
    end
  end

  call_args = args.map do |type, name|
    case type
    when 'int'
      "INT2NUM(#{name})"
    when 'int*'
      "INT2NUM(*#{name})"
    when 'char*'
      "rb_str_new2(#{name})"
    else
      name
    end
  end

  receiver = 'cNagaqueen'

  if call_args[0] == 'this'
    receiver = '(VALUE)(this)'
    call_args.shift
  end

  str_cstr_start, str_cstr_end = nil
  if ftype == 'char *'
    str_cstr_start = 'rb_string_value_cstr((VALUE*)('
    str_cstr_end   = '))'
  end

  <<EOF
#{ftype} nq_#{fname} (#{def_args.join(', ')})
{
  #{str_cstr_start}rb_funcall(#{receiver}, rb_intern("#{fname}"), #{call_args.length}#{', ' if call_args.length > 0} #{call_args.join(', ')})#{str_cstr_end};
}

EOF
end

def generate_code(line)
  if line =~ /^([^ ]*(?: )\*?)nq_(.*)\((.*)\);/
    type, name, args = $1, $2, $3

    args.gsub!(' *', '* ')
    args = args.split(',').map(&:strip).map(&:split)

    func(type, name, args)
  end
end

dir = File.expand_path(File.dirname(__FILE__))

nq=File.join(dir, '..', 'nagaqueen', 'nagaqueen.h')
bph=File.join(dir, '..', 'nagaqueen', 'boilerplate.h')

boilerplate = open(nq).read.each_line.map do |line|
  next unless line =~ /(void|char) .*nq_/
  generate_code(line)
end.join('')

File.open(bph, 'w') {|f| f.puts boilerplate }


