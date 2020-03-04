#include <ansi.h>
inherit NPC;
inherit SELLMAN;

void create()
{
        set_name(HIR"�w���J"NOR,({"joshua fireseed","fireseed","joshua"}) );
        set("title",MAG"�]��������"NOR);
        set("long","�@�W�P�y���q�r���W�ű��H�], ť���L�W���b���~
3002�~�k����, ���Q���m��@���x��ĥ, �{�U���O
�R���F�_�c��x�����ķ�F�I\n");
        set("sell_list",([
__DIR__"wp/mag.c"  : 5,
__DIR__"wp/cannon.c"  : 5,
__DIR__"wp/mag_clip.c"  : 5,
__DIR__"wp/cannon_clip.c"  : 5,
__DIR__"wp/pistol.c"  : 5,
__DIR__"wp/pistol_clip.c"  : 5,
__DIR__"wp/tranquilizer.c"  : 5,
__DIR__"wp/anesthetize.c"  : 5,
__DIR__"wp/anesthetize_clip.c"  : 5,
        ]) );
        set("age", 29);
        set("level", 67); 
        setup();
}
void init()
{
        add_action("do_list","list");
        add_action("do_buy","buy");
}
void die()
{
        object ob;
        
        if( !ob = query_temp("last_damage_from") ) ob = this_player(1);
        if( !ob )
        {
                ::die();
                return;
        }
     message("world:world3:vision",
HIG"\n�i�P�ڮ����j"+HIW"����-"HIR"�w���J"HIW"�Q"+ob->name(1)+"�e���k�פF�I�I\n\n"+NOR,users());
        write("�]���A��U�P�ھ�ĵ�}��, �ҥH�n���t�W�ɤF!!");
           ob->add("popularity",5);
        ::die();
        return;
}
