#include <ansi.h>
inherit NPC;
void create()
{
        set_name(GRN "�a��b�ϤH" NOR, ({"green bariour", "bariour"}));
        set("long",@LONG
�b�ϤH�ݰ_�ӹ��H���A�L�V�X�F�H�M�Ϫ��S�x�Ӥ��O�H�M���C�q�y���H�U���ݰ_�ӹ��O�@ 
�ӱj�����ϡC�y���H�W�A�ݤW�h���H�A�u�O�b�e�B�W�����@���s�������C 
LONG
        );
        set("gender", "�k��");
        set("title","�Ϩk���g�c");
        set("race", "human");
        set("level", 40);
        set("age", 30);
        set("env/wimpy", 10);         //�k�]wimpy (10%)
        set("evil",-20);                //���c�� -20 (�������c, �t���})
        set("attitude", "peaceful");   //�ũM�� NPC�C
        setup();
        add_money("coin", 1600 );
        carry_object("/open/world1/eq/fur_waist")->wear();
        carry_object("/open/world1/eq/bs_boots")->wear();
        carry_object(__DIR__"obj/bariour_claw")->wield();
        carry_object(__DIR__"obj/bariour_fur");
}
void die()
{
        object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob )
        {
                ::die();
                return;
        }

        if( 
        mapp(ob->getToDo("/open/quest/bariour_q2.c")) 
            && random(100) < 40
            && !objectp(present("_ANGLE_EGG_", ob))
        ) {
                new("/open/lottery/angle_egg")->move(this_object());
        }

        ::die();
        return;
}



