inherit ROOM;

void create()
{
  set("short", "�p����");
  set("light",1);
  set("long", @LONG
�o�̬O�@���p�p�����A���Ѩө��ȤH����������A�ȡC
LONG);
  set("exits", ([ /* sizeof() == 1 */
      "west" : __DIR__"room15",
     ]));
  set("objects",([
      __DIR__"npc/bank-keeper" : 1,
     ]) );
  set("room_type","bank"); 
  set("no_clean_up", 0);
  setup();
  replace_program(ROOM);
}
