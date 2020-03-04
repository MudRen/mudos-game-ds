inherit ITEM;
#include <ansi.h>
void create()


{
        set_name(CYN"�Ϣ��"HIC"�۰���b��"NOR, ({"atm transfer machine", "machine"}));
        set("unit", "�O");
        set("long",HIW"�@�ӯ}�}����b�����A���O�榡��: transfer <�ƶq> coin to ���aID"NOR);
        set_weight(999999);     
        set("no_get",1);
        set("no_sac",1);
        setup();
}
 
void init()
{

        add_action("do_transfer", "transfer");
}

int do_transfer(string arg)


{
        string from, usr;
        int amount;
        object from_ob, me, usr_ob;

        me = this_player();
        if( !arg || sscanf(arg, "%d %s to %s", amount, from, usr)!=3 )
                return notify_fail("���O�榡�Rtransfer <�ƶq> coin to <���a>\n");
	if( amount < 1 ) return notify_fail("�A�b�~����E\n");
        usr_ob = LOGIN_D->find_body(usr);
        if( !usr_ob ) return notify_fail("�S���o�ӨϥΪ�\n");                
        from_ob = new("obj/money/"+from);
        if( me->query("bank/past") < amount) return notify_fail("�A�Ȧ�̨S���o��h��\n");
         tell_object(me, 
                "�A�N "+HIY+ chinese_number(amount) + NOR+" "+from_ob->query("base_unit")+from_ob->query("name")+"�׵�"+usr_ob->query("name")+"\n");
         tell_object(usr_ob,HIW"�i"HIG"��"NOR+GRN"��"HIG"�q"NOR+GRN"��"HIW"�j"NOR+me->query("name")+"�׵��A "+HIY+chinese_number(amount)+NOR+" "+from_ob->query("base_unit")+from_ob->query("name")+"\n");

        if( me->query("bank/past") == amount ) me->delete("bank/past"); 
        else me->add("bank/past", -amount);
        usr_ob->add("bank/past", amount);
        return 1;

}

