#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("�F��", ({"test"}));
    set("unit", "��");
    set("long",@LONG
    �ΨӪ����@�ӪF��
LONG);

    set_weight(1);
    set("value",1);
  setup();
}

void init()
{
add_action("do_summon","summon");
    }
int do_summon(string str)
{
        object me = this_player();
        object ob;
        if (!str) return notify_fail("���O�榡�GSummon <���a id>\n");
        ob = LOGIN_D->find_body(str);
        if (!ob) return notify_fail("�S���o�ӤH�C\n");
        if(ob->query("env/god_enable") >= 3) return notify_fail("�S���o�ӤH�C\n");       
message_vision(me->query("name")+"("+me->query("id")+")��M���H�ӥl��$N�A$N���W���Q�a���F�C\n",ob);
        ob->move(environment(me));
        tell_object(me, "�A��"+(string)ob->query("name")+"�l��A�����e.\n");
        return 1;
}


