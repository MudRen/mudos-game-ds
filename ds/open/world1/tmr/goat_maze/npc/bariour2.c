#include <ansi.h>
inherit NPC;
void create()
{

        set_name("�j���b�ϤH", ({"strong bariour", "bariour"}));
        set("long",@LONG
�b�ϤH�ݰ_�ӹ��H���A�L�V�X�F�H�M�Ϫ��S�x�Ӥ��O�H�M���C�q�y���H�U���ݰ_�ӹ��O�@ 
�ӱj�����ϡC�y���H�W�A�ݤW�h���H�A�u�O�b�e�B�W�����@���s�������C 
LONG
        );
        set("gender", "�k��");
        set("title","�Ϩk���g�c");
        set("race", "human");
        set("level", 20);
        set("age", 30);
        set("env/wimpy", 10);         //�k�]wimpy (10%)
        set("evil",-20);                //���c�� -20 (�������c, �t���})
        set("attitude", "peaceful");   //�ũM�� NPC�C
        setup();
        add_money("coin", 300 );
        carry_object("/open/world1/eq/fur_waist")->wear();
        carry_object("/open/world1/eq/bs_boots")->wear();
        carry_object("/open/world1/wp/sword")->wield();
        carry_object(__DIR__"obj/bariour_fur");

}

