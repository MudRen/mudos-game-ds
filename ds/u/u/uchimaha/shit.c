#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIW"�իK�K"NOR,({"white shit","shit"}));
        set("long","�o�O�@�@�D�`�}�����զ�K�K, �O�Q���ܶ±M�Ϊ����M�C\n");
        set("race","���~");
        set_weight(30000);

        set("limbs", ({"����","�ݳ�","����" }));
        set("verbs", ({ "bite","claw","crash" }));

        set("level",50);
        set("age",2);

        set_temp("apply/damage",10);
        set_temp("apply/armor", 15);
        set_skill("unarmed",100);
        set_skill("bagi_fist",100);
        set_skill("dodge",50);
        set_skill("parry",50);
        set_skill("windmove",50);
        map_skill("unarmed","bagi_fist");
        map_skill("dodge","windmove");
        
        set("no_get",1);
        set("no_drop",1);
        set("amount",1);
        set("ridable",1);

        set("chat_chance",1);
        set("chat_msg",({
  (: command("dog") :),
  (: command("cat") :),
  this_object()->name()+"�b���ǾǪ��s�C\n",
  (: command("pure") :),
  (: command("jump") :),
  (: command(":D") :),
  (: command(":)") :),
  (: command(":P") :),
}));
        set("unit","�@");
        set("value",40000);
        set("member0","none");
        set("member1","none");
        set("member2","none");
        setup();
}

void init()
{
        add_action("do_member","member");
        add_action("do_run","run");
        add_action("do_name","name");
}

int ride_before_action(object me)
{
        object ob=this_object();
message_vision("$N�κɤF�O��, ���A�F"+this_object()->name()+"�C\n",me);
        //me->set_temp("apply/short",({ me->short()+HIY"< ���M��"NOR+this_object()->name()+HIW" >"NOR}));
        return 1;
}

int ride_after_action(object me)
{
        message_vision("$Níí�����b"+this_object()->name()+"�����W�F�C\n",me);
        //this_object()->set_weight(10);
        //this_object()->move(me);
        return 1;
}

int ride_off_action(object me)
{
        message_vision("$N�q"+this_object()->name()+"���I�W�L�F�U�ӡC\n",me);
        //me->delete_temp("apply/short");
        return 1;
}

int do_member(string arg)
{
        int n_save;
string where;
        object me;
        me=this_player();
        if( !arg || sscanf(arg,"here at %d",n_save)!=1 )
                return notify_fail("���O�榡: member here at <�ĴX�ӰO��>. \n");
        if( n_save > 3 || n_save < 1)
                return notify_fail("�իK�K���ȨS�A�O�o����h�a...�C\n");
        n_save -= 1;
        where=(string)file_name(environment(me));
        message_vision("$N�V�O�s�իK�K��o�̪�����O�_�ӡC\n",me);
        set("member"+n_save, where+".c");
        return 1;
}

int do_run(string str)
{
        int n_save;
        string arg;
        object me=this_player();

        if( !me->query_temp("ride") )
                return notify_fail("�A�èS���M�۰��C\n");
        if( me->query_temp("horse_run") )
        return notify_fail("�A���b�M�۰����Y�a�e�i����C\n");
        if( !str || sscanf(str,"at %d",n_save)!=1 )
                return notify_fail("���O�榡: run at <�����ĴX�ӰO��>. \n");
        if( n_save > 3 || n_save < 1 )
                        return notify_fail("�S�o�ӰO�г�....�C\n");
        n_save -= 1;
        arg = this_object()->query("member"+n_save);
        if( arg=="none" || !arg ) 
                return notify_fail("�A�n���S���s�e�O����A�ҥH�e�èS����������C\n");
        if( arg==(string)file_name(environment(me))+".c" )
                return notify_fail("�A���N�b�o�̤F�H\n");
        tell_room(environment(me),me->name()+"�M�ۥL��"+this_object()->name()+"���W�ѥh�C\n",({ me }));
        me->move("open/world1/cominging/area/npc/obj/runwait");
        tell_object(me,"�A�}�l���Y�a�e�i�D�D�D\n");
        me->start_busy(10);
        me->set_temp("horse_run",1);
        call_out("for_go",3,me,this_object(),arg);
        call_out("for_go1",10,me,this_object(),arg);
        call_out("for_go2",13,me,this_object(),arg);
        return 1;
}

void for_go(object me,object ob,string where)
{
        object go_room;
        go_room = load_object(where);
        message_vision(HIY"$N�M��$n�w�C����"+go_room->query("short")+"�e�i�h�D�D�D�D�D\n"NOR,me,ob);
        return;
}

void for_go1(object me,object ob,string where)
{
        object go_room;
        go_room = load_object(where);
        message_vision(HIC"�C�C���A$N�w�֨�F�F�ت��a�F�D�D�D�D�D�D\n"NOR,me);
        return;
}

void for_go2(object me,object ob,string where)
{
        me->move(where);
        tell_object(me,HIR"�A��F�F�ت��a�F�I���\n"NOR);
        tell_room(environment(me),me->name()+"��M�q�@�Ӧa���M�ۥL��"+ob->name()+"�����b�A���e�C\n",({ me }));
        ob->move(me);
        me->delete_temp("horse_run");
        return;
}
void die()
{
object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        LOGIN_D->set_reboot(0);
        if( ob ) message("world:world1:vision", HIW"\n  [�p�D����]:"HIC"\n\n\t�ǻ������i�R "HIW"�իK�K"HIC"���M�Q"+ob->name(1)+"���ߪ��R�차��̥h�F!!\n\n"+NOR,users());
        ::die();
        return;
}

