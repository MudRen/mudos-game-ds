inherit ROOM;
void create()
{ set("short","暫存房間");
  set("long","這是一間暫存房間");
  set("no_goto",1);
  setup();
  set("stroom",1);
  call_out("only_delay",1); }
void only_delay()
{ new("/open/world1/wp/ds_staff")->move(this_object()); }
