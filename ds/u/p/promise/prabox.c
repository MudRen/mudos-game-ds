// �q CS ��Ckboy/box.c
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIM"����"NOR, ({"box"}));
        set("long","������l���p����\n�ϥΤ�k: ���� pra <�Y��(�H)>\n���� unpra\n");
        set("unit", "��");
}

void init()
{
        if( this_player()==environment() )
        add_action("do_pra","pra");
        add_action("do_unpra","unpra");
}

int do_pra(string arg)
{
        object me,*inv;
        int i;
        me=this_player();
        inv = all_inventory(environment(me));
        if(!arg) return notify_fail("�A�n�ꦨ��?\n");
        if(me->query("pra")) return notify_fail("�A���ۤw�g���@�F!\n");
                for(i=0; i<sizeof(inv); i++)
                  {
                   if( arg == inv[i]->query("id"))
                    {
                        me->set("pra/bak_name", me->query("name"));
                        me->set("pra/bak_title", me->query("title"));
                        me->set("pra/bak_nickname", me->query("nickname"));
                        me->set("pra/bak_id", me->query("id"));
                        me->set("pra/bak_gender", me->query("gender"));
                        me->set("pra/pra", 1);
                        me->set("name", inv[i]->query("name"));
                        me->set("title", inv[i]->query("title"));
                        me->set("nickname", inv[i]->query("nickname"));
                        me->set("id", inv[i]->query("id"));
                        me->set("gender", inv[i]->query("gender"));
                        write(HIW"�A���X�������������ꦨ�F"HIY+inv[i]->query("name")+"\n"NOR);
                        say(HIC+me->query("pra/bak_name")+HIW+"���X�������������ꦨ�F"HIY+inv[i]->query("name")+"\n"NOR);
                        return 1;
                  }
        return notify_fail("�o�̨S�o�ӤH?\n");
}

int do_unpra(string arg)
{
        object me;


        me=this_player();

        if(!me->query("pra")) return notify_fail("�A�S����!!\n");

                me->set("name", me->query("pra/bak_name"));
                me->set("title", me->query("pra/bak_title"));
                me->set("nickname", me->query("pra/bak_nickname"));
                me->set("id", me->query("pra/bak_id"));
                me->set("gender", me->query("pra/bak_gender"));
                me->delete("pra");

                write(HIW"�A�N�ۨ��F, �^�_�쥻������\n"NOR);
                say(HIC+me->query("name")+HIW+"�N�ۨ��F, �^�_�쥻������\n"NOR);
                return 1;
}


