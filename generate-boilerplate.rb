#!/usr/bin/env ruby

require 'pp'

# void nq_setTokenPositionPointer(void *this, int *tokenPosPointer);

def func(ftype, fname, args)
  ftype.strip!
  fname.strip!
  args.map {|x| x.map(&:strip) }

=begin
  args.map! do |x|
    type, name = x
    type = case type
    when 'void*'
        # TODO: Check if VALUE will actually work in place of void*
      'VALUE'
    else
      type
    end

    [type, name]
  end
=end

  def_args = args.map do |x|
    if x.is_a?(Array)
      x.join(' ')
    else
      x
    end
  end

  call_args = args.map do |type, name|
    # Should work: https://github.com/ruby/ruby/blob/trunk/README.EXT#L140
    if name == 'self'
      name = '(VALUE)(self)'
    end

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

  <<EOF
#{ftype} nq_#{fname} (#{def_args.join(', ')})
{
  rb_funcall(cNagaqueen, rb_intern("#{fname}"), #{call_args.length}, #{call_args.join(', ')});
}

EOF
end

def generate_code(line)
  if line =~ /^\/\/([^ ]*(?: )\*?)nq_(.*)\((.*)\);/
    type, name, args = $1, $2, $3

    args.gsub!(' *', '* ')
    args = args.split(',').map(&:strip).map(&:split)

    # Switch 'void *this' with 'VALUE self'
    #args[0] = ['VALUE', 'self'] if args[0][1] == 'this'
    args[0][1] = 'self' if args[0][1] == 'this'

    #pp [type, name, args]
    func(type, name, args)
  end
end

nq="./nagaqueen/nagaqueen.h"
bph="./nagaqueen/boilerplate.h"

boilerplate = open(nq).read.each_line.map do |line|
  next unless line =~ /(void|char) .*nq_/
  generate_code(line)
end.join('')

File.open(bph, 'w') {|f| f.puts boilerplate }


