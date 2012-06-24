#include <ruby.h>

VALUE cNagaqueen,
      ast;

#include <stdbool.h>

// Hackity hack hack.
// Ideally this would be a .c file, but I don't feel like fighting extconf.rb
#include "boilerplate.h"

#include "nagaqueen.h" // Hacky

//extern int nq_parse(VALUE self, char *path);
int _nq_parse(VALUE self, char *path) {
    GREG *G = YY_ALLOC(sizeof(GREG), 0);
    G->buflen = 0;

    NagaQueenCore *core = YY_ALLOC(sizeof(NagaQueenCore), 0);
    core->yylineno = 0;
    core->this = &self;
    core->path = path;
    core->stream = fopen(path, "r");
    nq_setTokenPositionPointer(core->this, core->token);
    if(!core->stream) {
        printf("Not found: %s\n", path);
        return -1;
    }

    G->data = core;

    while (yyparse(G)) {}
    fclose(core->stream);

    return 0;
}

VALUE rb_nq_parse(VALUE self) {
  int ret;
  VALUE filename = rb_cv_get(self, "@@filename");

  ast = rb_cv_get(self, "@@ast");
  ret = _nq_parse(self, StringValueCStr(filename));

  return (ret == 0 ? Qtrue : Qfalse);
}

void Init_nagaqueen() {
  cNagaqueen = rb_define_module("Nagaqueen");
  rb_define_module_function(cNagaqueen, "_parse", rb_nq_parse, 0);
}

