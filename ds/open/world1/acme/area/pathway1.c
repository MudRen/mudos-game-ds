/// Room: /u/a/acme/area/pathway1.c

inherit ROOM;

void create()
{
	set("short", "�p��");
	set("long", @LONG
�o�̬O�q���Ѵ򪺤p���A�P��ɬO��a�A�n��i�ݨ줤���s���A��
�n�䦳�@���ľQ�A�F�������i���@���p���A�����G�O�[�L�H�ϦӪ����F
����C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"pathway2",
  "south" : __DIR__"street6",
   "northwest" : __DIR__"smallway",
]));
	set("no_clean_up", 0);
         set("objects",([
            __DIR__"npc/guan" : 1,
         ]) );
 
     set("outdoors","land");

	setup();
}
void init()
{ 
         add_action("do_enter","enter");
}
int do_enter(string arg)
{
          object me;
          me=this_player();
          if(arg != "�p��")
            return 0;
          else {
            message_vision("$N���}�F�����O���F�䪺�p�����F�L�h�C\n",me);
            me->move(__DIR__"pathway");
            return 1;
          }
}
