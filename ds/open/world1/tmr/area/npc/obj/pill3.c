inherit ITEM;
inherit F_PILL;
void create()
{
        set_name("���F��", ({ "u-len pill", "pill" }));
        set("long",@LONG
�@���Ŧ⪺�p�ĤY�A���O�����q�`�����F���A�ѩ��󤺫l����
�q�B�A�̬O���樫���򪺪Z�v���ҷR�ΡC
LONG
);
        set_weight(455);
        if( clonep() ) 
                set_default_object(__FILE__);
        else {
        	set("unit", "��");
        }
        set("value", 150);
	set("heal",([ "ap": 40,]));
        setup();
}


