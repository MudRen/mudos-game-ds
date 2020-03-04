// Room: /u/a/acme/area2/t20.c

inherit ROOM;

void create()
{
        set("short","�խߦa��[�a�U�G�h]");
	set("long", @LONG
�o�̬O�խߦa�����a�U�G�h�A�|�P���t�����A�������ˡA�b�A���Ǯg�Ӥ@
�D�N�N�������A�O�A�P��L�����O�A�����O�_�~�򩹫e��C�b�A���e������
�ݨ������k�G�ƪ��j�۬W�A�۬W�򦨤@�Ӷ��A�b�۬W�����o���ӹӸO�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"t19",
]));
  set("item_desc", ([ /* sizeof() == 1 */
"�ӸO" : "�o�O�@�Ӭ۷��ª��ӸO�A�W�Y��ۤ@�Ӥj�r�i�ޡj�A�����G�@�}�N����a���ˤl�C\n",
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
          if(arg != "�ӸO")
            return 0;
          else {
            message_vision("$N�ΤO�@�}���ӸO��h�A�u���ӸO���n�ӷ��A����{�F�ӥX�f�C\n\n",me);
            message_vision("$N���}�]����o�ӥΤO�Ө��ˬy��A�����@�_�@�_���A��������í�C\n",me);
            set("exits", ([
               "east" : __DIR__"t19",
               "westdown" : __DIR__"t21",
            ]));
            me->receive_wound("left_leg",10);
            return 1;
          }
}
int valid_leave(object me, string dir)
{
       if( dir=="westdown" && !userp(me) )
                return notify_fail("���̥u�����a�~��i�h�C\n");
    if( userp(me) && objectp( present("__GUARD__", this_object()) ))
            return notify_fail("�o�̤ӹL�����F�A�A�����L�h�C\n");
        return ::valid_leave(me, dir);
}
