// Room: /u/s/suez/area/hotel_room.c
inherit ROOM;
void create()
{
	set("short", "���Y");
	set("long",@LONG 
�嶮�����Y�A�s�쪺�a�O���o�X�Ií���𮧡A�맮���]�p���S������
�����a���M�M�s���G�Ať�ۨ��b�a�O�W���}�B�n�A���G�a�O�٬O�S�O�[��
�A�γ\�o�˴N���|���s�̪����}�a�o���R���a�O�C�A���F�N�O�q���ӤW
�ȩЪ�����A�H�Ϋȴ̪�����F�C
LONG
       );
	set("exits", ([ /* sizeof() == 1 */
                   "eastup" : __DIR__"hotel_step",
               "east": __DIR__"hotel_back",
            "west": __DIR__"hotel_hall",

              ]));

        set("objects",([
              __DIR__"npc/drooler_man" : 1,
              ]) );

	set("no_clean_up", 0);
        set("light",1);
	setup();
}
void init()
{
        add_action("do_push", "push");
}

int do_push(string arg)
{
        object me;
        me=this_player();
     
      if(me->query("class1")!="�K�P��") return notify_fail("�A�b�a�O�W�F�N�N��N�N�A�O�H�٥H���A�O�b���a�O�O�I\n");

        if (arg != "�a�O"  )
                return 0;
              else 
        {
            message_vision("$N���F���a�O�A��M�a�O����_�ӡA$N�����J�a�O���U�I\n",me);
        me->move(__DIR__"base_1");
      tell_room(environment(me),me->query("name")+"�ѱK�D���������F�U�ӡC\n",me);
        return 1;
        }
}
