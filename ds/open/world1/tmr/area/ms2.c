#include <room.h>
#include <ansi.h>
#include <path.h>

inherit ROOM;


void reset_citronm() {
        // ���s�]�w��ʼƶq
       set("citron", 5 + random(10));
}

void create()
{
        set("short", "����p��");
        set("long", @LONG
�A�����b�@�����䪺�d�ڸ��A�D����ǬO���C�A����ʥСA�����a�G
������Цa�A�Pù�ѧG�����b�ɨ��������~§�C�b��n�観���p����A�A
���F�B�����i���ۤp���~�򩹫e���C
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
          "west" : __DIR__"ms4",
          "east" : __DIR__"ms1",
          "southwest" : __DIR__"ms3",
      "north" : WD_PAST+"meadow/room1",
        ]));
        set("item_desc",([
         "���" : "�@�����A��Ӥj����ʡA�ݤF�u�O�H�Q����(pick)�X�����|�|�ݡC\n",
        ]) );   
        set("outdoors","land");
        set("no_clean_up", 0);
       set("citron", 5 + random(10));
 
        setup();
        call_out("reset_citronm", 180);
}

void init()
{
        add_action("do_pick","pick");
}

int do_pick(string arg)
{
        object me;
        object citron;

        me=this_player();
        if(arg != "���") return notify_fail("�A�n�K����??\n");
        message_vision("$N���F�����L���f���A�����N�N�a���i�h�ʥи�..\n",me);

        if( query("citron") <= 0 )
                tell_object(me,"�A�b�ʥдM�V�F�@�}�A�רs�䤣��i�Y����ʡC\n");
        else {
                add("citron",-1);
                citron=new(__DIR__"npc/obj/citron");
                citron->move(me);
                tell_object(me,"�A�b�ʥа��K�F���w���z����ʴ��b�h�̡C\n");       
        }
        return 1;       
}

