#include <dbase.h>
#include <name.h>
inherit ITEM;
//inherit F_FOOD;
void create()
{
        set_name("������", ({ "breath pill", "pill" }));
        set("long",
                "�������]�O�����ұ`�Ϊ��ĤY�A�D�n�O�Ψӫ�_�w���h����O�A��j\n"
                "�ɤY�Φ��۷����C\n");
        set("weight", 20);
        if( clonep() ) 
                set_default_object(__FILE__);
        else {
                set("unit", "��");
        set("value",250);
                set("heal_mp",40);
        set("food_remaining",1);
        }
        setup();
}

void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        string type,msg;
        object ob,me;
        me = this_player();
        ob = this_object();
        if( !ob->id(arg) ) return 0;
        if( me->is_busy() )
                return notify_fail("�A�W�@�Ӱʧ@�٨S�������C\n");

        if( query("heal_hp"))
        {
                this_player()->receive_heal("hp", query("heal_hp"));
        }
        
        if( query("heal_mp"))
        {
                 this_player()->receive_heal("mp", query("heal_mp"));
        }
        
        if( query("heal_head"))
        {
                this_player()->receive_curing("head", query("heal_head"));
        }

        if( query("heal_body"))
        {
                this_player()->receive_curing("body", query("heal_body"));
        }

        if( query("heal_hand"))
        {
                this_player()->receive_curing("hand", query("heal_hand"));
        }

        if( query("heal_foot"))
        {
                this_player()->receive_curing("foot", query("heal_foot"));
        }

        if( this_player()->is_fighting() ) this_player()->start_busy(2);

        set("value", 0);
        message_vision("$N���_$n, �@�f��]�F�U�h�C\n", this_player(),this_object());
        // This allows customization of eating effect.
        query("pill/function");
        if(stringp(msg=query("eff_msg"))) tell_object(this_player(),msg+"\n");
        if( !this_object()->finish_eat() )
                destruct(this_object());

        return 1;
}

int is_pill()
{
        return 1;
}