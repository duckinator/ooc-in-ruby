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
    nq_setTokenPositionPointer(self, core->token);
    if(!core->stream) {
        printf("Not found: %s\n", path);
        return -1;
    }

    G->data = core;

    while (yyparse(G)) {}
    fclose(core->stream);

    return 0;
}

VALUE rb_nq_init(VALUE self, VALUE filename) {
  int ret;

  ast = rb_cv_get(self, "@@ast");
  ret = _nq_parse(self, STR2CSTR(filename));

  return (ret == 0 ? Qtrue : Qfalse);
}

void Init_Nagaqueen() {
  cNagaqueen = rb_define_class("Nagaqueen", rb_cObject);
  rb_define_method(cNagaqueen, "initialize", rb_nq_init, 0);
}

