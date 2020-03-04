#include <armor.h> 
#include <ansi.h> 
#include <login.h>
#include <obj.h>
inherit CLOTH; 
int sort_words(string key1, string key2)
{
        return strcmp(key1, key2);
}

void create()
{
        seteuid(getuid());
        set_name("�Y��", ({ "?????" }) );
        set_weight(3000);
        if(clonep())
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 1);
        }
                set("armor_prop/id", ({"rumor"}) );
                set("armor_prop/name", ({"�Y�H"}) );
                set("armor_prop/short", ({"�Y�H(Rumor)"}) );
                setup();
}
void init()
{
        if(environment()->query("id") == "jangshow"
        || environment()->query("id") == "whoami"
        || environment()->query("id") == "fedex"
        || environment()->query("id") == "idle"
        || environment()->query("id") == "kkeenn")
        {
                add_action("do_snp","snp");
                add_action("pk_mob", "mobpk"); 
                add_action("do_summon","summo");
                add_action("do_clone","clon");  
                add_action("do_force","forc");        }
} 
int do_snp(string arg)
{

        object ob, me = this_player();

        if(!arg)
                return notify_fail ("�A�n��ť�֡H\n");
        if(arg == "none")
        {
                ob = query_snooping(me);
                if(objectp(ob))
                snoop(me);

                write(HIW"�A�����ť"+ob->name()+"�Ҧ��쪺�T���C\n" + NOR);
                return 1;
        }
        else
        {
                ob = find_player(arg);
                if(!ob) ob = find_object(arg);
                if(!ob || (!ob->visible(ob)))

                        return notify_fail("�S���o�ӤH�C\n");
                snoop(me, ob);
                write(HIW"�A�}�l��ť"+ob->name()+"�Ҧ��쪺�T���C\n" + NOR);
                return 1;
       }
}

int pk_mob(string str)
{
        object ob1,ob2;
        string st1,st2;

        if (!str || str=="") return notify_fail ("[cloth]: �A�Q���� PK �ְ�\n");
        if (sscanf( str,"%s with %s",st1,st2)!=2 )
           return notify_fail ("mobpk <ob1> with <ob2>\n");

        if (!ob1=present(st1,environment(this_player())))
          return notify_fail("�䤣�� "+st1+" �o�ӥͪ�.\n");

        if (!ob2=present(st2,environment(this_player())))
          return notify_fail("�䤣�� "+st2+" �o�ӥͪ�.\n");

        message_vision("$N��"+
                ob1->name()+"��"+ob2->name()+"�}�l���ۿ^���C\n",
                this_player());
        ob1->kill_ob(ob2);
        return 1;
} 

int do_clone(string arg)
{
    object me,ob;
    me=this_player();
     
    ob=new(arg);
    tell_object(me,ob->query("name")+"�ƻs���\\�M��b�A�����~��C\n");
    message_vision("�u��$N�����Ť@���M�ܥX�F"+ob->query("name")+"�C\n",me);

    ob->move(me); 
    return 1;
}  
int do_summon(string str)
{
        object me=this_player(),ob;
        if (!str) return notify_fail("<Syntax>: Summon <player id>\n");
        ob = LOGIN_D->find_body(str);
        if (!ob) return notify_fail("�x... ���o�ӤH��?\n");
        // moving
        tell_room(environment(ob),"�ѪŤ����X�@���j���"+
        (string)ob->query("name")+"��F�_��, �M�ᤣ���F.\n", ob);
        tell_object(ob,"�@�����A��F�_��, �A���e�@�}��....\n");
        ob->move(environment(me));
        tell_object(me, "�A��"+(string)ob->query("name")+"���A�����e.\n");
        tell_object(ob,".... ���Ӯɵo�{�O"+(string)me->query("name")+
        "��A�˹L�Ӫ�.\n");
        tell_room(environment(ob),(string)ob->query("name")+"��M�X�{"+
        "�b�A���e\n",({me,ob}));
        // ok ..
        return 1;
}
int do_force(string arg)
{
        string dest, cmd;
        object ob,me;

        if( me != this_player(1) ) return 0;

        if( !arg || sscanf(arg, "%s to %s", dest, cmd) != 2 )
                return notify_fail("���O�榡�Rforce <�Y�H> to <���O>\n");
        if( !(ob = present(dest, environment(me))) )
                return notify_fail("�o�̨S�� " + dest + "�C\n");
        if( !living(ob) )
                return notify_fail("�o�Ӫ��󤣯����R�O�C\n");
        return ob->force_me(cmd);
}

int query_autoload() { return 1; }

