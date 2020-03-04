#include <ansi.h>
inherit NPC;
int do_sell_all(object me);
void create()
{
        set_name("�Ǩ���",({"stranger of named charles","charles","seller"}));
        set("level",1);
        set("race","�H��");
        set("age", 33);
        set("no_fight",1);
    set("long",HIW"�R�h Hotel ��ť�H��ƪ�"HIC"�����y����"HIW"�A�A���q�ߩ�ı�o�A�L�O�өǤH�C\n"NOR);
        setup();
}
void init()
{
        add_action("do_sell","sell");
}
int do_sell(string arg)
{
      object ob,me;
        int valu;
        me=this_player();

        if(!arg) return notify_fail("�A�n�椰��F��H\n");
        if(arg=="all")
        {
                do_sell_all(me);
                return 1;
        }
        if(!ob=present(arg,me))
                return notify_fail("�A�S���o�˪F��C\n");
        valu=ob->query("value");
        if( ob->query("money_id") )
                return notify_fail("��..���? �ڤ����H�~�����C\n");
        if( valu<20 )
                return notify_fail("�o�F�褣�ȿ��C\n");
        if( ob->query("secured") )
                return notify_fail("�Х��Ѱ��O�s���A�C\n");
        if( ob->query("no_drop") )
                return notify_fail("�o�ӪF��ܯS�O, �A�٬O�ۤv�O�ަn�F�C\n");
        if( ob->query("no_sell") )
                return notify_fail("�ڤ����ʳo�تF��C\n");
        if( ob->is_character() ) 
                return notify_fail("�ڤ����ʬ����F��C\n");
        if(ob->query("equipped") )
                return notify_fail("�Х������U�Ӧn�ܡH\n");
        arg = ob->query("id");

        valu = valu/3+random(valu/5);
        message_vision("$N�H"+chinese_number(valu)+"�������A��F�@"+ob->query("unit")+ob->query("name")+"���Ǩ����C\n",me);
        valu-= valu/10;
        tell_object(me,"�Ǩ�����F�@�������A�����A�פF"+chinese_number(valu)+"��A�������b��̡C\n");
        me->add("bank/past",valu);
                destruct(ob);
        me->save();
        return 1;
}
int do_sell_all(object me)
{
       object *inv;
       int i,money,cost;
        money=0;
        inv = all_inventory(me);
        for(i=0;i<sizeof(inv);i++)
        {
                if( inv[i]->query("value") < 20 ) continue;
                if( inv[i]->query("secured") ) continue;
                if( inv[i]->query("equipped") ) continue;
                if( inv[i]->query("money_id") ) continue;
                if( inv[i]->query("no_drop") ) continue;
                if( inv[i]->query("no_sell") ) continue;
                if( inv[i]->is_character() ) continue;
                cost=inv[i]->query("value")/3+random(inv[i]->query("value")/5);
                message_vision("  $N�H"+chinese_number(cost)+"�������N"+inv[i]->name()+"�浹�F$n�C\n",me,this_object());
                money+=cost;
                destruct(inv[i]);
        }
        if(money<1)
        {
                tell_object(me,"  �A�S���F��i�H��F�C\n");
                return 1;
        }
        message_vision("\n$N�o�ǪF���`�@�H"+chinese_number(money)+"�������浹�Ǩ����C\n",me);
        money-= money/10;
        tell_object(me,"�Ǩ�����F�@�������A�����A�פF"+chinese_number(money)+"��A�������b��̡C\n");
        me->add("bank/past",money);
        me->save();
        return 1;
}
