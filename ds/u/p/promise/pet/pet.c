#include <path.h>
#include <ansi.h>
inherit ITEM;
inherit F_AUTOLOAD;
inherit F_SAVE;
void create()
{
        object me;
        me=this_player();
        set_name(HIR"���]��"NOR,({"beastbox"}));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", @LONG
�o�O�@��M���]�~�����l�C
<��X�]�~(pput �]�~��id)>
<���X�]�~(pget �d����id)>
LONG);
                set("unit", "��");
                set("no_sell",1);
                set("no_drop",1);
                set("value",50000);
                set("amount",1);
        }
}
int query_autoload() { return 1; }
void init()
{
        add_action("do_get","pget");
        add_action("do_home","pput");
}
int do_get(string arg)
{
        object npc,pet;
        object me;
        int lv,bage;
        if(!this_player())
                return 0;
        me=this_player();
        npc=present("beastbox",me);
        bage=me->query("beast_age",1);
        if(!npc)
                return 1;
        if(environment(me)->query("no_cast")||environment(me)->query("no_kill"))
                return notify_fail("�ФŦb�o���X�]�~\n");
        if(me->query("diebeast"))
                return notify_fail(HIW"�A���]�~�w�g���F\n"NOR);
        if(me->query_temp("pet")>0)
                return notify_fail(HIW"�@���u��@���d�����]�~�O�@�A\n"NOR);
        if(me->query("mud_age")-bage<30)
                return notify_fail(HIW"�A���ݵ��@�U�~��b���X�]�~\n");
        if(arg==me->query("bname"))
        {
                if(me->query("bname")=="wind")
                        pet = new("/u/p/promise/pet/beast-w");
                else if(me->query("bname")=="blood")
                        pet = new("/u/p/promise/pet/beast-b");
                else if(me->query("bname")=="ice")
                        pet = new("/u/p/promise/pet/beast-i");
                else return notify_fail("�ثe�ள���u��wind ice blood�T���]�~\n");
                me->delete("beast_age");
                if(!me->query("beast_age"))
                        me->set("beast_age",me->query("mud_age"));
                pet->set("owner",me->query("id"));
                pet->set_temp("owner",me->query("id"));
                pet->restore();
                pet->set("pet",1);
                if(pet->query("hp")<1)
                        pet->set("hp",1);
                pet->set_temp("pet",1);
                pet->set_leader(me->query("id"));
                pet->invocation(me);
                pet->set("actions",(: call_other, "/adm/daemons/race/beast.c", "query_action" :));
                pet->move(environment(me));
                lv=pet->query("level");
                pet->set_name(pet->query("name"),({me->query("id")+" "+me->query("bname")+" beast","beast"}));
                pet->set("dex",lv*2);
                pet->set("str",lv*2);
                pet->set("con",lv*2);
                pet->set("lck",lv*2);
                pet->set("air",lv*2);
                pet->set("int",lv*2);
                pet->set("wis",lv*2);
                pet->set("mus",lv*2);
                pet->set("max_hp",pet->query("con")*400);
                pet->set("max_mp",pet->query("int")*30);
                pet->set("max_ap",pet->query("mus")*40);
                pet->set("max_force",pet->query("air")*40);
                if(me->query("bname")=="blood")
                {
                        pet->set_temp("apply/damage",pet->query("level")*6);
                        pet->set_temp("apply/hit",pet->query("level")*6);
                        pet->set_temp("apply/armor",pet->query("level"));
                }
                if(me->query("bname")=="wind")
                {
                        pet->set_temp("apply/damage",pet->query("level")*1);
                        pet->set_temp("apply/hit",pet->query("level")*6);
                        pet->set_temp("apply/armor",pet->query("level")*3);
                }
                if(me->query("bname")=="ice")
                {
                        pet->set_temp("apply/damage",pet->query("level")*3);
                        pet->set_temp("apply/hit",pet->query("level")*6);
                        pet->set_temp("apply/armor",pet->query("level")*2);
                }
                if(pet->query("force")>pet->query("max_force"))
                        pet->set("force",pet->query("max_force"));
                if(pet->query("ap")>pet->query("max_ap"))
                        pet->set("ap",pet->query("max_ap"));
                pet->set("title",me->query("name")+"��");
                me->set_temp("pet",1);
                me->set_temp("bname",me->query("bname")+" beast");
                message_vision(HIC+me->query("name")+"�ѫ��]�������X�@��"
                       +pet->query("name")+HIC"\n"+pet->query("name")
                        +HIC"�Ө�"+me->query("name")+"���}��\n"NOR,me);
        }
        else return notify_fail(HIG
                "\t�Y�A�i���O���]�~�Х�pget wind..\n"+
                "\t�Y�O���]�~�Х�pget blood..\n"+
                "\t�B�]�~���ܬO��pget ice\n"NOR);
        return 1;
}
int do_home(string argx)
{
        object npc;
        object me;
        if(!this_player())
        return 0;
        me=this_player();
        if(argx==me->query("bname"))
        {
                if(!me->query("name")||!me)   return 0;
                npc=present(me->query("id")+" "+me->query("bname")+" beast",environment(me));
                if(!npc)
                        return notify_fail(HIW"�o��S�o��mob\n"NOR);
                if(npc->query("owner")!=me->query("id"))
                        return notify_fail(HIW"�o���]�~���O�A��\n");
                message_vision(HIC+me->query("name")+"�N���䪺"+
                npc->query("name")+HIC"�^���]����\n"NOR,me);
                npc->save();
                destruct(npc);
                me->delete_temp("pet");
                me->delete_temp("bname");
        }
        else printf(HIC"�A���i�L�o���]�~��...??\n"NOR);
        return 1;
}

