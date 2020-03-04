inherit ROOM;

void create()
{
        set("short", "�A��");
        set("long", @LONG
�A�����b�ж��p���A���U�|��A�ɬO������誺�A�a�A�Ф����ٴ���
�@�ӽ_��H�A�魯�������ͪ��۩_�����ᦷ�A�ո̳z�šA�Q���㲴�C�b�A
���F��i�ݨ��@���p�T�ΡC
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"farm",
  "west" : __DIR__"farm2",
  "east" : __DIR__"cottage",
// ��bug "southeast" : __DIR__"gosenwu",
  "southeast" : __DIR__"pass10",
]));
       set("objects",([
          __DIR__"npc/sparrow" : 4,
       ]));
     set("item_desc", ([
            "�ᦷ" : "�o����s�u�sŽ���Ū�v�A�γ\\�A�i��K(pick)�U���C\n",
     ]) );      
      set("no_clean_up", 0);
      set("outdoors","land");
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
        if(query_temp("herb3")) return notify_fail("����H\n");
        if(arg != "�sŽ���Ū�")
        {
            notify_fail("�A�n�K�U����H\n");
            return 0;
        }
        else {
        message_vision("$N�p���l�l���N�sŽ���Ū�K�F�U�F�C\n",me);
        herb=new(__DIR__"obj/herb3.c");
        herb->move(me);
        set("item_desc", ([
            "����" : "�o����֬\\���F�A���S����γB�C\n",
        ]) );      
        set("long", @LONG
�A�����b�ж��p���A���U�|��A�ɬO������誺�A�a�A�Ф����ٴ���
�@�ӽ_��H�A�魯�����ͪ��۳\�h����C�b�A���F��i�ݨ��@���p�T�ΡC
LONG
        );
        set_temp("herb3",1);
        call_out("delay",600,this_object());
        return 1;
             }
}
void delay(object room)
{
     delete_temp("herb3");
     set("item_desc", ([
            "�ᦷ" : "�o����s�u�sŽ���Ū�v�A�γ\\�A�i��K(pick)�U���C\n",
     ]) );      
}
