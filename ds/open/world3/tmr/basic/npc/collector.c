#include <ansi.h>
inherit NPC;
inherit SHOPMAN;
void create()
{
        set_name("�q�u�Y" , ({ "mineral collector","collector" }) );
        set("long",@long
�L�O�o���q�Ϫ��u�Y�A�M�������q�u�ұĶ��Ө쪺�q���C�L�ݰ_�Ӭ�
���͵��A���L���a��A�I�Y�A�M��S�I�Y�B�z���a���q���A�ݰ_�Ӭ۷�
���ԳҡC
long
);
        set("level",5);
        set("race","�H��");
        set("age", 33);
        set("attitude", "peaceful");   //�ũM�� NPC�C
        set("storeroom",__DIR__"mineralroom"); //�`�N. �n�إߤ@��room��F��
        setup();
}
void init()
{
        add_action("do_sell","sell");
}

