#include <ansi.h>
inherit NPC;

void create()
{
        set_name( "����O�޽c", ({ "moneyman","man" }));
       set("long","�@�ӫܳ�ª��H�A���O���W�n���a�ۤ��ֿ��C\n");
        set("level",10);
        set("title",HIR"�ЦV�ڭn��"NOR);
        set("gender", "�k��");
        set("race", "human");
        set("age", 20);
                                        
        set("str",30);
        set("dex",30);
        set("con",10);
        set("int",30); 
        set("combat_exp",10000);
        set("evil",0);
        set_skill("unarmed",50);
        set_skill("combat",50);
        set_skill("dodge",50);

        set("attitude", "peaceful");
        set("inquiry/money", @LONG
�ڪ��D�H���{�b�����D�p�����ڵ���
���..�a�D�H....@@
LONG );
        setup();
        add_money("coin", 20000);
        add_money("dollar", 20000);
        carry_object("/open/world1/award/superpill");
carry_object("/open/world1/acme/area/npc/obj/god_pill"),2;
      carry_object("/open/world2/eq/life_glasses")->wear();
}
