inherit ROOM;
void create()
{
        set("short", "�۱V�W");
        set("long", @LONG
�o�̬O�u�y�i��v�������H�����۱V�W�A�o�̪��۾������F�C�a
�ҥH�۷��ơA�b������F�@�ǤQ���S�O���Ӫ��A���a�����Ҭ۷�
�S��~�|�ͪ��o�دS�O���Ӫ��a�I
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 1 */
]));
       set("objects",([
          __DIR__"npc/bonze" : 1,
       ]) );
     set("item_desc", ([
"�Ӫ�" : "�A�J�Ӫ��@�F�@�o��Ӫ��A�oı���ǪG��A�o���G��U�١y�M�ߥۺ�G�z�A�A�i�H�K(pick)�U���C\n",
  "�۱V" : "�o�O�@�Ӭ۷�~�k���۱V�A�n��(climb)�U�h�o�p�ߤ@�I�C\n",
     ]) );
        setup();
}
void init()
{ 
         add_action("do_climb","climb");
         add_action("do_pick","pick");
}
int do_climb(string arg)
{
          object me;
          me=this_player();
          if(arg != "�۱V")
            return notify_fail("�A�n�k������H\n");
          else {
            message_vision("$N�p�߲��������U�۱V�C\n",me);
            me->move(__DIR__"way6");
            return 1;
          }
}
int do_pick(string arg)
{
          object me;
           object pill;
          me = this_player();
          if(arg != "�M�ߥۺ�G")
            return notify_fail("�A�n�K�U����F��H\n");

            if( query_temp("pick") )
                return notify_fail("�A�oı�ѤU���G�곣�O���������A�ҥH�٬O���n�K�n�F�C\n");
            message_vision("$N�p���l�l���K�U�F�@���G��C\n",me);
            pill=new(__DIR__"obj/herb4");
            pill->move(me);
            set_temp("pick", 1);
            call_out("delay",600,this_object());
            return 1;
}
void delay(object room)
{
     delete_temp("pick");
     return;
}

