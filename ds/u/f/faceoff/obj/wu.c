inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("�a��", ({ "ti chnu", "chnu" }));
        set("long",@LONG
�o�O�@�ت��b�a���W, �����@�o���������ħ�, ���M�S���C�H
�Ӫ��H, �����ǷL�r��, �]���]���A�y�ͦY, ���L�����U�譱��
���ĭˤ]����, �S���S�O��X.
LONG
);
        set_weight(45);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material","plant");
                set("value", 34);
                set("heal_ap",10);
                set("heal_hp",10);
		set("heal_mp",10);
                set("attr_one","plant"); 
                set("attr_two","yin");  
                set("food_remaining", 1);  
                set("eat_msg","$N�]�U�@�Ӧa��\n");
                set("eff_msg","�A�yı�ݤf��e����, ���h�p�� ! !\n");
        }
        setup();
}

void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object me;
        if( !this_object() ) return 0;
        if( !this_object()->id(arg) ) return 0;
        me=this_player();
        if(me->query("mp")<19)
        {
                return notify_fail("�A���믫�O(MP)�w�g�����F, �A�Y�N�}���o�C\n");
        }
        else
        {
                set("heal_ap",30);
                me->receive_damage("mp",20);      
                me->receive_damage("ap",20);      
                return ::do_eat(arg);
        }
}
