#include <ansi.h>
inherit NPC;
int service();
int service1(object,int);
int service2(object,int,int);
int service3(object,int,int);
void create()
{
        set_name(HIW"���"NOR , ({"reihi"}));
        set("long",@LONG
    �b�A���e���O�u�Z�^���q�v�Ȫ�������Q�A�̶��⪺���v���b�����
���@���g�A�ˤ������e�ΰ�ť���n�����H�ѫo�h�ҡA�o���H���Pı�N�O�y
���H�νw�C�A���O�q�ӨS�H���o���A�ȡA�ƹ�W����p���h���ȤH�A�o
�]�`�O���I���ӡC�b�o�S���Ʊ����ɭԡA�o�`�O�@��ݵ���W�����e�X��
�A�@���ۤ@�������W�����l�C

    �A�i�H��"lodge ����"�ӦV��ƭq�СC
LONG
);
       set("gender","�k��");
       set("age", 31);
       set("level", 10);

       set("chat_chance", 3);
       set("chat_msg", ({
            "��ƻ�����ۦ��l:�u�ա�հա�ա���հա����v\n",
	    "��Ʊq�p�кݥX�谵�n���Ʋz�C���n����I\n",
            "��ƻ������C���b�ȤH�����C\n"
             }));
        set("inquiry",([
  "����" : "��...�ڭ̦��T�ػ������A��...���ڬݬ�...���O�O100���B500���H��1000���C",
  "�q��" : "�п�Jlodge�[�W�z�ҭn�I������...���¡I(��Ƶ��A�@�ӿˤ����L���C)",
  "���l" : "�ڡI�o���l...�o���l�O....��...�@��...�B��...�g���ڪ�....",
  "�Z�^���q" : "�o�Ӷǻ��ܬ��a�I�ڭ̩��̥��n���u�C�֤H�A�z�i�Hťť�o�۳o�Ӷǻ��C",
  "�A��" : "100�����A�ȬO�@���ײ����\\�I�A500���i�H�b�Ф��R�����𮧡A�L�]�h�O1000���A���¡C",
]));
        setup();
}
void init()
{       
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                command("say ��...�w����{...");
                command("smile");
        }
        add_action("do_lodge","lodge");
}

int do_lodge(int arg)
{
        object ob=this_player();
        int num;
         if(!arg) return notify_fail("�A����J�A�Q�I�������C\n");
        if(sscanf(arg, "%d", num)==1) {
        if (num < 100) return notify_fail("���:�u��....�̧C���O�B�O100����...�v\n");
                if( !ob->can_afford(num) )  return notify_fail("�A�S�a����h���I\n");

                ob->set_temp("lodge_level",num );
                ob->receive_money(-(ob->query_temp("lodge_level")));
                tell_object(ob,"���:�u�ڭ̷|�ھڱz�ҥI�������Ӵ��ѦX�A���A�ȡC�v\n");
                service();
                return 1;
        }
        return 0;
}
int service()
{
        object ob;
        int x,b;
        ob=this_player();
        x = ob->query_temp("lodge_level");
        if (x > 1000) x = 1000;
        ob->set_temp("lodge_level",x );
        b = (x/100);
        tell_object(ob,"��ƱN�A�a��@�ӪŦ짤�U�C\n");
        ob->set_temp("is_busy/lodge","�A���j�\\�٨S�ӡA�A�����a�I");
        call_out("service1",b,ob,b);
} 
int service1(object ob,int b)
{
        tell_object(ob,"�A�ȥͱN�\\�I�ݤF�X�ӡA���n����I\n");
        if(b > 5) b= 5;
 if(b!=0) {
        tell_object(ob,HIM"�A�b�ξA�����ҤU�z�z�����Y���ײ����\\�I�C\n"NOR);
        ob->set_temp("is_busy/lodge","�A���b�Y���C");
        ob->receive_heal("hp",(ob->query_con()/2));
        b--;
        call_out("survice1",2,ob,b);
        }
 else { 
        if(ob->query_temp("lodge_level")>499)
        {
                call_out("service2",2,ob,(ob->query_temp("lodge_level")),5);
                return 1;
        }
        else{
                tell_object(ob,"����Y���u���C\n");

                ob->delete_temp("is_busy/sleeping");
                ob->delete_temp("lodge_level");
                ob->receive_heal("hp",20);
                tell_object(ob,"��ƷL����:�u���¥��{�C�v\n");
                return 1;
        }
      }

}
int service2(object ob,int b,int t)
{
        tell_object(ob,HIB"�A�ȥͬݧA�Y���F�A�K�a�A��G�Ӫ��ж���\n"NOR);
        ob->set_temp("is_busy/lodge","�O��A�C�C�𮧡C");
        ob->move(__DIR__"npc/obj/hotel_room");
        
         if(b!=0) {
                switch(random(7))
                {
                case 1: tell_object(ob,YEL"�A���b�ξA���ɤW�u�Ӻu�h�C\n"NOR );break;
                case 2: tell_object(ob,CYN"�Ať�ۥ~���ǨӪ��u���q�n�C\n"NOR );break;
                case 3: tell_object(ob,HIB"�A���Y��o�ж������\\���C\n"NOR );break;
                case 4: tell_object(ob,GRN"�A�׽��b�ɤW�ݵۤp���C\n"NOR );break;
                case 5: tell_object(ob,HIG"�A���_�Ӧ��F���i�y�C\n"NOR );break;
                case 6: tell_object(ob,HIY"�A���P�������٦סA�}�l�o�b�C\n"NOR );break;
		case 0: tell_object(ob,HIC"�A�a�b����A�ݵۨӨө������H�s�C\n"NOR );break;
                }
        t--;
        call_out("survice2",5,ob,b,t);
                }
         else { 
                if(ob->query_temp("lodge_level")>999)
                {
                        call_out("service3",2,ob,(ob->query_temp("lodge_level")),10);
                        return 1;
                }
                else{
                        tell_object(ob,"�A�g�L�𮧫�A�믫�����C\n");
                        tell_object(ob,"�A���d�i��z�h�СC\n");
                        ob->move(__DIR__"port_24");
                        ob->delete_temp("is_busy/sleeping");
                        ob->delete_temp("lodge_level");
                        ob->receive_heal("hp",(b+50));
                        ob->receive_heal("ap",(b+30));
                        ob->receive_heal("mp",(b+20));
                        tell_object(ob,"��ƷL����:�u���¥��{�C�v\n");
                        return 1;
                }
        }

}
int service3(object ob,int b,int t)
{       
         tell_object(ob,BLU"�A�˦b�ɤW�S�h�[�A�N�i�J�F���e���ڶm�C\n"NOR);
         ob->set_temp("is_busy/lodge","�O�x�F�A�A���b��ı�C");
        
         if(b!=0) {
                switch(random(7))
                {
                case 1: tell_object(ob,CYN"�ϸ��L�F�]��.....�C\n"NOR );break;
                case 2: tell_object(ob,HIW"�F�l���L�F�ϧw.....�C\n"NOR );break;
                case 3: tell_object(ob,YEL"�@�����q�}��]�F�L�h.....�C\n"NOR );break;
                case 4: tell_object(ob,GRN"�v�ܩi�q�������_��X.....�C\n"NOR );break;
                case 5: tell_object(ob,HIM"�@����R�����D....���b�����R....�C\n"NOR );break;
                case 6: tell_object(ob,MAG"�@�ӭ^�T�����l....����t�r�k�q....�C\n"NOR );break;
		case 0: tell_object(ob,RED"�A�ڨ�DS�����Y�̥H�ΥL�̻����N����.....\n"NOR );break;
                }
        t--;
        call_out("survice3",10,ob,b,t);
                }
         else { 
                        tell_object(ob,"�ΤF�@ı�A�Aı�o�����R���F���O�C\n");
                        tell_object(ob,"�A���d�i��z�h�СC\n");
                        ob->move(__DIR__"port_24");
                        ob->delete_temp("is_busy/sleeping");
                        ob->delete_temp("lodge_level");
                        ob->receive_heal("hp",(b+200));
                        ob->receive_heal("ap",(b+150));
                        ob->receive_heal("mp",(b+150));
                        tell_object(ob,"��ƷL����:�u���¥��{�C�v\n");
                        return 1;
                }
        

}
