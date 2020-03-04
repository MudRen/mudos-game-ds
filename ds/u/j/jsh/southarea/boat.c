#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "小船上");
        set("long", @LONG
這是一艘用木片黏接而成的小船，在船的前面，有兩條繩子，�
向前一探，原來綁著一條海豚。
LONG
        );
        set("item_desc", ([ /* sizeof() == 1 */
  "海豚" : "一隻純白色的海豚, 樣子十分可愛, 似乎是用來拖船用的(slap)。\n",
]));
        set("exits", ([ /* sizeof() == 2 */
          "out" : __DIR__"startroom",
       ]));
        set("light",1);
        set("no_clean_up", 0);

        setup();
}
void init()
{
        add_action("dolphin","slap");
}


int dolphin(string arg)
{
        int t;
        object me,room,*inv;
        me=this_player();
        if(arg != "海豚") return 0;
        if(!this_object()->query_temp("moving")) 
        {
                inv = all_inventory(this_object());
                message_vision( HIB "$N往海豚的後背打了下去，海豚慢慢擺\動尾巴，緩緩的把船拖出漁港.....\n\n" NOR ,me);
                me->start_busy(4);
                call_out("domessage",3,3);
                this_object()->set_temp("moving",1);
                this_object()->delete("exits");
                room = load_object(__DIR__"startroom");
                room->delete("exits/enter");
                room->set("long",@ROOM_LONG
這裡是漁港的海岸，環繞著四海，一望無際，只瞧見南方有一塊小島。
ROOM_LONG
);
                tell_room(room,"你看到小船緩緩的離開了漁港....\n");
                return 1;
        }else
        {
                tell_object(me,"小船已經離開到看不到遠處了。\n");
                return 1;
        }

}

int domessage(int b)
{
  object *inv,room;
  int i;
  if(b==3) tell_room(this_object(),HIC "海豚慢慢的游，船也慢慢的往南方移動了...\n\n" NOR);
   else if(b==2) tell_room(this_object(), HIC "前端的海水，有如被刀劃開，把細細的水氣噴了上船 . . .\n\n" NOR );
  else if(b==1) tell_room(this_object(), HIG "海豚漸漸的慢了下來，原來是到岸了，只見一片茂密的森林 . . .\n\n" NOR );
  else  {
                inv = all_inventory(this_object());
                tell_room(this_object(),HIW "你下了船走上沙灘, 走進了彎曲不直的路..\n\n" NOR );
                this_object()->delete_temp("moving");
                room = load_object(__DIR__"room1");
                tell_room(room,"你看到一隻海豚拖著小船游回港了..\n");
                for(i=0;i<sizeof(inv);i++)
                {
                        if(living(inv[i])) inv[i]->move(__DIR__"room1");
                }
                tell_room(room,"海豚轉頭就游.....\n");
                this_object()->set("exits", ([
                        "out" : __DIR__"startroom",
                ]));
                room = load_object(__DIR__"nb4");
                tell_room(room,"你看到一隻海豚拖著小船游回港了..\n");
                room->set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"/open/world1/wu_sha_town/seacoun42",
  "enter" : __DIR__"boat",
]));
                room->set("long",@ROOM_LONG2
這裡是漁港的海岸，環繞著四海，一望無際，只瞧見南方有一塊小島。在你南邊停著一艘小船。
ROOM_LONG2
);
                return 1;
                
        }
        b--;
        call_out("domessage",3,b);
}

