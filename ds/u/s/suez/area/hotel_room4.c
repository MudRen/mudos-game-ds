// Room: /u/s/suez/area/hotel_room.c
inherit ROOM;
void create()
{
	set("short", "�p��");
	set("long",@LONG
�o�p�θ̳��M�O�@�ӷŬu�A�~�����p�ˬy�J�����ϳo�ӷŬu�ä��Q��
�����A�]�S�������D������A�ϭˬO�ˤl�����D����@�P�A�T�|���˸���
�b�����W�A�@�������ƪ����Y���C�b�ǡA�z�L�p���ӨӪ��˼vĬĬ���T�A
�A�ݤF�u�Q���U�h�n�n�~�Ӿ��C�Ŭu�Ǧ����p��P�A�W���g�ۡu�ɦˬu�v
�C
LONG
       );
	set("exits", ([ /* sizeof() == 1 */
                   "bridge" : __DIR__"hotel_back",
            ]));
         set("item_desc",([
        "�p��P":"��P�W�g�ۡu�ɦˬu�v,�U���٦���p�r�u���Τ��A�ФŦb���~���C�v\n",
        "���Y":"�W�������F�C�a�A��⪺���A�ܦn�ݡA�ݨӳo���O���q���C�a�C�x�H��򦳤@�Ӧa��S���C�a�H�n�����H�`�`Ĳ�N�o�a�誺�ˤl�C\n",
         ]));
	set("no_clean_up", 0);
        set("light",1);
	setup();
}
void init()
{
        add_action("do_drink", "drink");
        add_action("do_knock", "knock");

}

int do_drink(string arg)
{
       object me;
      int pplmp;
        me=this_player();    
      pplmp=me->query("mp");
      if (arg != "�u��" ) return 0;
      message_vision("$N����ŤF�@�ǷŬu���ܤU�h�C\n",me);
     me->start_busy(2);
      if(pplmp <10)
       {
      tell_object(me,"�ڡI�S�S�S�S�I�o�̪��Ŭu���ݨӤ�A�Q�����ټ��C\n");
         return 0;
     }
     else
      {
       tell_object(me,"���������𶶵۫|��y�J�|�Ϧ��e�����A�y�ɧAı�o�n�h�F�I\n");
       call_out("cure_all",1,me);
     me->receive_damage("mp", 5 );
       return 1;
     }
      
}

int do_knock(string arg)

{
        object me;
        me=this_player();
        if(arg != "���Y") return 0;
        message_vision("$N�H�@�W�S���`���V���ۥ��Y�A�u���p�ξa�s������w�w�W�ɡA�S�X�@�����t���q�D�C\n\n",me);
         set("exits", ([
               "enter":__DIR__"hole_out",
                   "bridge" : __DIR__"hotel_back",
        ]));
        return 1;
}