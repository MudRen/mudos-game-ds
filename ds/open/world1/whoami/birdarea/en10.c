#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
set("short",HIW"�F�_"NOR"�A�L"HIW+BLK"��"HIY"���ެ}�f"NOR);

set("long",@LONG
�o�O�@�B���W���}�ޤf�A�@�p��{���q�}�����_�ƨӡA�@��
���w���Pı�o�M�ӥ͡A�n���H�ɷ|�o�ͥi�Ȫ��Ʊ��A�A�B�Y�}�l
�_�X�N���A�ߩ��̭����C�ܵ۬O�_�n�i�}�̤@�@�C
LONG);
 
 set("exits",(["southeast":__DIR__"en9",
    ]));
   set("item_desc",([
        "�}":"�A�¬}�̬ݤF�ݡA���Y���¤@�����򳣬ݤ���A

        ���O�A�o���F�@�Ѥ����`����{��...\n",

        ]));
 set("no_clean_up", 0);
 setup();
}           
void init()
{
        add_action("do_enter","enter");
}

int do_enter(string arg)
{
        object me,b;
        me=this_player();
        if (!arg || arg =="")
        return notify_fail("�A�n�i�h���̡H\n"); 
        if( me->is_busy() )
        return notify_fail("�A�٦b���I\n");
        if (arg != "hole" && arg != "�}") return 0;
        if ( me->query_temp("can_enter") ){
        message_vision("\n\t$N���_�i���"HIY"����"NOR"�e�i�F�I\n" ,me);
        me->move(__DIR__"fox1.c"); 
        me->start_busy(2); 
        me->delete_temp("can_enter"); 
                call_out("girl",600,this_object());
        if( sizeof(filter_array( children(__DIR__"npc/qgirl"), (: clonep :) )) < 1 
        && (query_temp("no_girl")) < 1 
        && sizeof(filter_array( children(__DIR__"npc/kfox"), (: clonep :) )) < 1)
        { 
        __DIR__"fox18"->delete("exits/enter");
        b = new(__DIR__"npc/qgirl")->move(__DIR__"fox18");
        }
        tell_room(environment(me),me->query("name")+"���F�i��..\nn",me); 
        set_temp("no_girl",1);        } else { 
        tell_object(me,"�A�O�ݤ����r�٬O�Q��..�ӳo�̰�����H\n");}
        return 1;
}                  
void girl(object tob)
{
        delete_temp("no_girl");
        return;
}

