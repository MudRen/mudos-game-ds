inherit ROOM;
void create()
{
        set("short", "�߮���H��");
     set("light",1);
        set("long", @LONG
�o�̴N�O���񹣦W���߮���H��F�A�A�����Ǧ��\�h���H�Z�h�̥��b
��ѡA�]�����b�m�C�A�ݼˤl�ӭӳ��Z�N���j�A���C�ӤH�����e�i���A
�����]���O�m�Z���H�A�L�����ӳ��|�ܴL�q�A�A�A�o�{����n�����@
���p�����ˤl�C
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"map_1",
  "northeast" : __DIR__"map_4",
  "east" : __DIR__"map_3",
  ]));
  set("item_desc",([
        "�p��":"�A�q�p�������Gť��F�����ˤ��n..�A�i�H��(goin)�L�h�ݬݡC\n",
        ]));
    set("objects",([
       __DIR__"npc/fu_man" : 2,
    ]) );
         set("outdoors","land");
         set("no_clean_up", 0);
 setup();
  }
void init()
{
        add_action("do_goin","goin");
}

int do_goin(string arg)
{
        object me;
        me=this_player();
        if(!arg|| arg!="�p��") return 0;
        message_vision("$N���۸��������p�����h....�n���ּ֡C\n",me);
        me->move(__DIR__"fu");
        tell_room(environment(me),me->query("name")+"�q�p�������F�L�ӡC\n",({ me }) );
        return 1;
}


