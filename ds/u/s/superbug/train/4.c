// Room: /u/a/acme/area2/t20.c

inherit ROOM;

void create()
{
        set("short","�~�ⶡ");
	set("long", @LONG
�o�̬O�~�ⶡ�A�b�A������O�@���̭��A���e��F�@����l�A�٦��X
�Ӭ~��x�A�q���W���лx�A�i�H�o���A�b�A������O�k�Z�ҡA�k��O�k�Z
�ҡA�i�O�k�Z�Ҫ����W���F�@�i�u�Ȱ��ϥΡv���P�l�C
LONG
	);
    set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"6.c",
  "out" : __DIR__"2.c",
]));
  set("item_desc", ([ /* sizeof() == 2 */
  "�P�l" : "�@���g�ۡG�u�Ȱ��ϥΡv���P�l�Cn",
  "��" : "�@�����۵P�l�����A�ݰ_�Ӧ��G�i�H��}���Cn",
  ]) );
	set("no_clean_up", 0);

	setup();
}
void init()
{ 
         add_action("do_kick","kick");
}
int do_kick(string arg)
{
          object me;
          me=this_player();
          if(arg != "��")
            return 0;
          else {
            message_vision("$N�ΤO�@�}������h�A�u�������n�Ӷ}�C\n\n",me);
            message_vision("$N���}�]����o�ӥΤO�Ө��ˬy��A�����@�_�@�_���A��������í�C\n",me);
    set("exits", ([ /* sizeof() == 3 */
               "west" : __DIR__"6.c",
               "out" : __DIR__"2.c",
               "east" : __DIR__"7.c",
            ]));
            me->receive_wound("left_leg",10);
            return 1;
          }
}
int valid_leave(object me, string dir)
{
       if( dir=="westdown" && !userp(me) )
                return notify_fail("���̥u�����a�~��i�h�C\n");
        return ::valid_leave(me, dir);
}
