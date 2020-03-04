inherit ROOM;
void create()
{
        set("short", "�j��");
        set("long", @LONG
�A�|�P���t�����A�j�������M���\�w�[�A�����Q����áA�î�G�H�A�O�A
�Q�������A�A�|�U�i��ɡA�o�{�o�̦���Ӫ��A�@�{�@�{���A�٬O�n�ݡC
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"backyard.c",
]));
     set("item_desc", ([
         "�Ӫ�" : "�o��Ӫ��W�Y���C�ӵ����⪺�p�I�A�O�U�١u�C�P�������v\n"
                  "���Ӫ��A�A�i�H�K(pick)�U���C\n",
     ]) );      
        set("no_clean_up", 0);
        setup();
}
void init()
{
   add_action("do_pick","pick");
}
int do_pick(string arg)
{
        object herb;
        object me;
        me=this_player();
        if(query_temp("herb2")) return notify_fail("����H\n");
        if(arg != "�C�P������")
        {
            notify_fail("�A�n�K�U����H\n");
            return 0;
        }
        else {
        message_vision("$N�p���l�l���N�C�P�������K�F�U�ӡC\n",me);
        herb=new(__DIR__"obj/herb2.c");
        herb->move(me);
      set("item_desc", ([
              "�Ӫ�" : "�o�u�O�@������A�èS���S�O���B�C\n",
     ]) );      
        set("long", @LONG
�A�|�P���t�����A�j�������M���\�w�[�A�����Q����áA�î�G�H�A�O�A
�Q�������A�A�|�U�i��A�oı�o�̪ſ������A����F��]�S���C
LONG
        );
        set_temp("herb2",1);
        call_out("delay",600,this_object());
        return 1;
             }
}
void delay(object room)
{
     delete_temp("herb2");
     set("item_desc", ([
         "�Ӫ�" : "�o��ӤW�Y���C�ӵ����⪺�p�I�A�O�U�١u�C�P�������v\n"
                  "���Ӫ��A�A�i�H�K(pick)�U���C\n",
     ]) );      
}
