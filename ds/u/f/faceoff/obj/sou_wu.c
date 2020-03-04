inherit ITEM;
inherit F_FOOD;
void create()
{
        set_name("���Q", ({ "sou wu", "wu" }));
        set("long",@LONG
�o�O�@�ر`���������ħ�, �ĩ��ݳ�, �q�`�Q�Ψӽվi����, 
�]�i�ͭ�, �O�������ɫ~!
LONG
);
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("material","plant");
                set("value", 27);
                set("attr/wound",2);  
                set("heal_ap",15);
                set("heal_hp",5);
                set("attr_one","plant"); 
                set("attr_two","yin");  
                set("food_remaining", 1);  
                set("eat_msg","$N�]�U�@�ӭ��Q\n");
                set("eff_msg","�A�yı���Ь���⪺, �@�Ѥ����o�M�ӥ� ! \n");
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
        if(me->query("mp")<30)
        {
                return notify_fail("�A���믫�O(MP)�w�g�����F, �A�Y�N�}���o�C\n");
        }
        else
        {
                set("heal_ap",33);
                me->receive_damage("mp",31);         
                return ::do_eat(arg);
        }
}
