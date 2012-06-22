class OocParser
  rule(:break_kw     ) { str('break')      }
  rule(:continue_kw  ) { str('continue')   }
  rule(:return_kw    ) { str('return')     }

  rule(:func_kw      ) { str('func')       }
  rule(:class_kw     ) { str('class')      }
  rule(:cover_kw     ) { str('cover')      }
  rule(:enum_kw      ) { str('enum')       }
  rule(:interface_kw ) { str('interface')  }
  rule(:from_kw      ) { str('from')       }
  rule(:abstract_kw  ) { str('abstract')   }
  rule(:final_kw     ) { str('final')      }
  rule(:static_kw    ) { str('static')     }
  rule(:inline_kw    ) { str('inline')     }
  rule(:extends_kw   ) { str('extends')    }
  rule(:extern_kw    ) { str('extern')     }
  rule(:unmangled_kw ) { str('unmangled')  }
  rule(:implements_kw) { str('implements') }

  rule(:import_kw    ) { str('import')     }
  rule(:include_kw   ) { str('include')    }
  rule(:use_kw       ) { str('use')        }
  rule(:if_kw        ) { str('if')         }
  rule(:else_kw      ) { str('else')       }
  rule(:for_kw       ) { str('for')        }
  rule(:while_kw     ) { str('while')      }
  rule(:match_kw     ) { str('match')      }
  rule(:case_kw      ) { str('case')       }
  rule(:as_kw        ) { str('as')         }
  rule(:in_kw        ) { str('in')         }
  rule(:into_kw      ) { str('into')       }
  rule(:proto_kw     ) { str('proto')      }
  rule(:try_kw       ) { str('try')        }
  rule(:catch_kw     ) { str('catch')      }

  rule(:set_kw       ) { str('set')        }
  rule(:get_kw       ) { str('get')        }

  rule(:operator_kw  ) { str('operator')   }
  rule(:const_kw     ) { str('const')      }

  rule(:true_kw      ) { str('true')       }
  rule(:false_kw     ) { str('false')      }

  rule(:null_kw      ) { str('null')       }

  rule(:keyword) { break_kw | continue_kw | return_kw | func_kw |
                   covwer_kw | enum_kw | from_kw | abstract_kw | final_kw |
                   static_kw | inline_kw | extends_kw | extern_kw | unmangled_kw |
                   import_kw | include_kw | if_kw | else_kw | for_kw |
                   while_kw | as_kw | operator_kw | const_kw | null_kw | match_kw | case_kw |
                   try_kw | catch_kw }
end
