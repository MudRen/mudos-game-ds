#include <path.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", MAG"暗斯德塔大門"NOR);
        set("long", @LONG
                      !  !  ! �� �� !  !  !
                       !  I＿I＿I_�� �鱌I＿I＿I  !
                       I_/|＿|＿|_�� �鱌|＿|＿|\_I
                    ! /|_/|  |  | �� �� |  |  |\_|\ !
                    I//|  |  |  | �� �� |  |  |  |\\I       
                 ! /|/ |  |  |  | �� �� |  |  |  | \|\ !    
                 I//|  |  |  |  | �� �� |  |  |  |  |\\I    
              ! /|/ |  |  |  |  | �� �� |  |  |  |  | \|\ ! 
              I//|  |  |  |  |  | �� �� |  |  |  |  |  |\\I 
 _!＿!＿|！|=/|/ |  |  |  |  |  | �� �� |  |  |  |  |  | \|\=|！|＿!＿!_
 _I＿I＿|！||/|＿|＿|＿|＿|＿|＿|_�� �鱌|＿|＿|＿|＿|＿|＿|\||！|＿I＿I_
 -|═|═|！||-|═|═|═|═|═|══�� �礜丐弋═|═|═|═|═|-||！|═|═|-
  |  |  |！|| |  |  |  |  |  |  | �� �� |  |  |  |  |  |  | ||！|  |  |
  |  |  |！|| |  |  |  |  |  |  | �� �� |  |  |  |  |  |  | ||！|  |  |
  |  |  |！|| |  |  |  |  |  |  | �� �� |  |  |  |  |  |  | ||！|  |  |
  |  |  |！|| |  |  |  |  |  |  | �� �� |  |  |  |  |  |  | ||！|  |  |
 _|＿|＿|！||_|＿|＿|＿|＿|＿|＿|_�� �鱌|＿|＿|＿|＿|＿|＿|_||！|＿|＿|_
 -|═|═|！||-|═|═|═|═|═|═|-�� ��-|═|═|═|═|═|═|-||！|═|═|-
  |  |  |！|| |  |  |  |  |  |  | �� �� |  |  |  |  |  |  | ||！|  |  |
暗斯德塔的門口, 大門緊閉著, 從欄杆之間望進去, 令人有種說不出的神秘感.
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
            "northeast": __DIR__"dst2",
            "northwest": __DIR__"dst8",
            ]));
        set("no_clean_up", 0);
    set("outdoors","land");
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/poorguard2" : 1,
  __DIR__"npc/poorguard" : 1,
]));
     set("item_desc", ([
"大門" : "一扇緊閉著的大門, 上並無大鎖, 看來似乎應手即開(push), 問題
是, 天知道有什麼魔法附在上面?\n"
     ]));

        setup();
}
void init()
{
        add_action("typepush","push");
}
     int typepush(string arg)
{
        object me;
        me=this_player();
        if(arg != "大門") 
         return 0;
        else {
        message_vision(
        HIY "$N輕輕的推了一下, 大門便悄沒聲息的向兩旁滑了開來...\n\n" NOR ,me);
        message_vision( HIY "$N亦步亦趨的走了進去, 「嘎~~」的一聲響, 大門在$N身後自動關上...\n\n" NOR ,me);
        me->move(__DIR__"dstg1");
        return 1;
             }
}
