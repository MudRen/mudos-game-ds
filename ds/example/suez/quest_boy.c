#include <ansi.h>
inherit NPC;
inherit F_UNIQUE;
void start();
void die();
void reok();
//�M�w���a�ѨM���ȫ����o�ݩʡA�Ĥ@���������A�ĤG�������ߡA�ĤT�����·t�C//
int *sarsass = ({ 1, 1 , 1 });
void create()
{
        set_name( "�˦b��y�����֦~", ({ "boy" }));
        set("long", "�@�ӭ˦b��y�����֦~�C\n");
        set("level",10);
        set("gender", "�k��");
        set("age", 17);
        set("exp", 70);
        set("chat_chance", 15 );  
        set("chat_msg", ({        
                "�Aı�o���I���ӹ�l�C\n",
                "�֦~����L�O����ۧA�A�����R���F����C\n",
        }) );
        set("talk_reply","��...�ڧ�o�u�٫��٧A.....��L�ڧa�I...���٤��Q��........");
        set("inquiry", ([
        "�٫�" : "�ڮa�Q���ǰӤH�j��ʥh�F...�ڮ𤣹L....���W�S�S���F....�ҥH�ڤ~.....�C\n",
        ]));
        set("schedule",
        ([
        "03" : (: reok :),
         "23" : (: start :),
        ]));


        setup();
        carry_object(__DIR__"/eq/ring");
}



void init()
{
        int hpx;
        ::init();
        hpx= this_object()->query("max_hp");
        this_object()->receive_damage("hp", hpx*2/5 );
        add_action("do_steal","steal");
       add_action("do_say","say");
}
void start()
{
        object npc1,npc2;
     string AREA = "../port_"+(15+random(11))+"";
        npc1 = this_object();
        npc2 = new(__DIR__"bussniss_mn");
        if(!find_object("../port_b6")) return;
        npc1->move("../port_b6");
        npc2->move(""+AREA+"");
        npc2->die();
        tell_room(environment(npc2),HIR"�b�A���e�o�ͤF�@�_�j�s���H�סA�A�ݨ��ǤH���U���D����V�k�h�I�X�Ӯ��Z�����H�w�l�F�L�h�I\n"NOR);
        tell_room("../port_b1",HIR"�W��ǨӤ@�}�پx�n�A�@�D�¼v��M�q�A����«�L�C\n"NOR);
        tell_room("../port_b2",HIR"�_��ǨӤ@�}�پx�n�A�@�D�¼v��M�q�A����«�L�C\n"NOR);
        tell_room("../port_b3",HIR"�U���D���J�f�B���G�ǨӤ@�}��P���}�B�n�C\n"NOR);
        tell_room("../port_b4",HIR"�A�Q�@�ӤH�v���F�@�U�A�u�����H�v���ߤ�í�V��@�^�A���M��L����F�I\n"NOR);
        tell_room("../port_b5",HIR"�_��Ǩө_�Ǫ��n�T�C\n"NOR);
        //tell_room("../port_c4",HIR"�U���D���J�f�B���G�ǨӤ@�}��P���}�B�n�C\n"NOR);
        //tell_room("../port_c5",HIR"�U���D���J�f�B���G�ǨӤ@�}��P���}�B�n�C\n"NOR);
        //tell_room("../port_c6",HIR"�U���D���J�f�B���G�ǨӤ@�}��P���}�B�n�C\n"NOR);
        //tell_room("../port_c7",HIR"�U���D���J�f�B���G�ǨӤ@�}��P���}�B�n�C\n"NOR);
        //tell_room("../port_c8",HIR"�U���D���J�f�B���G�ǨӤ@�}��P���}�B�n�C\n"NOR);
        //tell_room("../port_c9",HIR"�U���D���J�f�B���G�ǨӤ@�}��P���}�B�n�C\n"NOR);
        return;
}
void greeting(object ob)
{
        int l,n,d;
        mixed *m=ob->query("sarsass_2");
        if( !ob || environment(ob) != environment() ) return;
        if( !ob->query("sarsass_2") && !this_object()->query_temp("ring"))
        {
                 ob->set_temp("sarsass_test_q",1);
                 tell_object(this_player(),@LONG
�o�O�@�W�m�ܧ٫��ñ��`�Q�`�̪��֦~�A�A�{�b�����M�w�p��B�m�L:
�@�B���H�v�R�A���F�L�N�٫����^�ӡC
�G�B�ݥL�i���A��@�S�ݨ�L���}�n�F�C
�T�B�i�H��L�L�A���O�L�����N�٫��٦^�Ӥ~��C(say �٫�)

LONG);  
}else
{
        l = m[0];
        n = m[1];
        d = m[2]; 
        if(l >= n && l > d)  tell_object(ob,"�z�W���ѨM�����D���`�M�����������C\n");
        if(n > l || n > d )  tell_object(ob,"�z�W���ѨM�����D���`�M���������ߡC\n");
        if(d >= n && d > l)  tell_object(ob,"�z�W���ѨM�����D���`�M�������·t�C\n");
        if(l = d )  tell_object(ob,"�z�W���ѨM�����D���`�M���������ߡC\n");     
}
}
int do_steal(string arg)
{
 if(arg=="boy")
 {
 tell_object(this_player(),"�]���\\�O�����g�X��������ʪ��{���A�ҥH�Ф��n�γo�ؤ覡�ӸѨM��Quest�C\n");
}
 return 1;
}
int do_say(string arg)
{
 object me = this_player();
 mixed *m=me->query("sarsass_2");
 if(arg=="�٫�" && !me->query("sarsass_2") && me->query_temp("sarsass_test_q")>0)
 {
 tell_object(me,"�A��֦~���i�H��L�L�A���O�٫��������k��D�C\n");
 tell_object(me,"�֦~�Ϊg���媺��N�٫��ǥX�ӡC\n");
 command("give ring to " + me->query("id") );
 this_object()->set_temp("ring");
 if(!m)  me->set("sarsass_2",sarsass);
 sarsass = m;
 if(m[0] < m[2]) {sarsass[1]++;
 if(m[0] > m[2]) {sarsass[0]++;
 if(m[0] = m[2]) {sarsass[2]--;
 //��������o�Ӧ欰�᪺�ݩʧ��ܡC//
 me->set("sarsass_2",sarsass);
}
 return 1;
}
void reok()
{               
                destruct(this_object());
}

void die()
{
        object me = this_player();
        mixed *m=me->query("sarsass_2");
        sarsass = m;
        if(environment( this_object() )=="shop.c")
        {
                destruct(this_object());
        }
        else{
         if(!me->query_temp("last_damage_from") )
         me = this_player(1);
         if(me->query_temp("sarsass_test_q")>0 && !me->query("sarsass_2"))
         {
                if(!m)  me->set("sarsass_2",sarsass);
                if(m[0] < m[2]) sarsass[2]++;
                if(m[0] > m[2]) sarsass[1]++;
                if(m[0] = m[2]) sarsass[0]--;
                //��������o�Ӧ欰�᪺�ݩʧ��ܡC//
                me->set("sarsass_2",sarsass);
         }
                ::die();
}}


