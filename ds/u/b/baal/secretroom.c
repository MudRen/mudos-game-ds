#include <ansi.h>
inherit ROOM;
void create()
{
 set("short",MAG"����"NOR);

 set("long",@LONG
�o�өж����˴˪�, �Ф��ߤ@���@������ݥߦb�@�Ӥp���W, �L�z
������b�۶��v������W��M�X�n�\���w���v�l, �|�P���\�h���[�l, �c
�l, �W�����n�F�h�p�p����...

LONG
    );
        set("objects",([
__DIR__"weapon/item_box" :1,
__DIR__"weapon/eq_shelf" :1,
__DIR__"weapon/wp_shelf" :1,
__DIR__"weapon/item_shelf" :1,
]));

        set("light",1);
 set("no_clean_up", 0);
 setup();

}
void init()
{
        add_action("typeclimb","climb");
}
     int typeclimb(string arg)
{
        object me;
        me=this_player();
        if(arg != "÷��") 
         return 0;
        else {
        message_vision(
        "$N���÷���A�C�C�����W�h...\n\n" ,me);
        me->move(__DIR__"workroom2");
        return 1;
             }
}

