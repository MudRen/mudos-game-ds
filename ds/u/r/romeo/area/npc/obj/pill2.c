inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIB"���_�p�ĤY"NOR, ({"Msg_Pill","pill"}) );
        set("long",
            "�o�O�@�ʧ��msg���ĤY.\n"
           );
        set("unit", "��");
        if( clonep() )
        set_default_object(__FILE__);
        else {
        set("base_unit", "��");
        set("value",30000);
        set("base_weight", 50);
             }
setup();
}
void init()
    {
    add_action("do_eat", "eat");
    }
    int do_eat(string str)
{
    object me;
    object ob;
    string msg_mout,msg_min,msg_home,msg_clone,msg_dest,msg_name,msg_title;
    ob = this_object();
    me = this_player();
    msg_mout = "�A�ϥ�goto���}�o�ж���, �o�ж����H�ݨ쪺�ԭz";
    msg_min = "�A�ϥ�goto�Ө�o�ж���, �o�ж����H�ݪ��ԭz";
    msg_home = "�A�ϥ�home�ɪ��ԭz";
    msg_clone = "�A�ϥ�clone�ɪ��ԭz";
    msg_dest = "�A�ϥ�dest�ɪ��ԭz";
    msg_name = "�A���W�r";
    msg_title = "�A��title";
    if("str == pill")
{
    message_vision(HIB"$N�Y�U�@�ɤp�ĤY�I.\n"NOR, me);
    me->set("env/msg_mout",msg_mout);
    me->set("env/msg_min",msg_min);
    me->set("env/msg_home",msg_home);
    me->set("env/msg_clone",msg_clone);
    me->set("env/msg_dest",msg_dest);
    me->set("name",msg_name);
    me->set("title",msg_title);
    destruct(this_object());
    return 1;
}
}

