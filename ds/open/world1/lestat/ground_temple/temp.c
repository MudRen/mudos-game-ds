inherit ROOM;
void create()
{ set("short","�Ȧs�ж�");
  set("long","�o�O�@���Ȧs�ж�");
  set("no_goto",1);
  setup();
  set("stroom",1);
  call_out("only_delay",1); }
void only_delay()
{ new("/open/world1/wp/ds_staff")->move(this_object()); }
