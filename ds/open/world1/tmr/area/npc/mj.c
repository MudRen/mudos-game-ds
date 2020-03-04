/*
����ɬq���~�R*Value being indexed is zero.

�{���Ropen/world1/tmr/area/npc/mj.c ��684��
����: open/world1/tmr/area/npc/mj#1924 ("���P�p�j")
��ƩI�s�^��:
���:do_win()           <- open/world1/tmr/area/npc/mj.c:��684�� [����:open/world1/tmr/area/npc/mj#1924 ("���P�p�j")]
=======================�H�W���~�кɧ֭״_========================

*/
//Aip@The.Never.Been.Place 6/16/1997
#include <ansi2.h>
inherit F_SAVE;
inherit NPC;
#define RECORD_PLAYERS 4
#define END 286
#define START 0
void check_flower(mapping who);
int to_say_play();
int to_say_rule();
int do_check_Mj(string datastr,string str);
int do_check_eat(string num1,string num2,string LastDump);
int delete_last_dump(string whoId);
int do_check_win(string str);
int check_hu(string strW);
int set_mjdata(object me,int *score);
int get_tc(mapping who);
varargs int do_dump(string str,object me);
varargs int do_touch(string str,object me);
varargs int wash_mj(int amount);
varargs int do_win(string str,object me);
varargs int do_gon(string str,object me);
varargs int do_pon(string str,object me);
string check_id(string str,string kind);
string do_delete_Mj(string datastr,string str,int amount);
string show_mj(string str,int flag);
string sort_data(string str);
mixed do_check_num(string str,int flag);
//�P�����
string MjE= "1w2w3w4w5w6w7w8w9w1t2t3t4t5t6t7t8t9t1s2s3s4s5s6s7s8s9seasowenojofabaf1f2f3f4f5f6f7f8";
string *MjC = ({"",
                "�@�U","�G�U","�T�U","�|�U","��U","���U","�C�U","�K�U","�E�U",
                "�@��","�G��","�T��","�|��","�","����","�C��","�K��","�E��",
                "�@��","�G��","�T��","�|��","���","����","�C��","�K��","�E��",
                "�F��","�n��","�護","�_��","����","�C�o","�ժO",
                "1 �K","2 �L","3 ��","4 �V","1 ��","2 ��","3 ��","4 ��","�t�b"
              });
int K;
string Tc = "";
//���
int Auto;
int Auto_Tin;
int Auto_Gon;
int Auto_Pon;
int Count;
int count;
int end;
int Goned;
int HU_F;
int NO_HU;
int NO_GON;
int Playing;
int Play;
int Times;
int Touched;
int NowPlayer;
int Player_leave;
string List ="";
string LookP ="";
string *NowPlayerId = ({ "","","","" });
string LastDumpId="";
string LastDump="";

mapping P1Data = ([
"Show": "color","Id": "","Name": "","Mj": "","Out": "","OutGon": "","OutPon": "",
"OutFlower": "","Auto": "","AutoTin": "","AutoGon": "","AutoPon": "","Dump": ""
               ]);
mapping P2Data = ([
"Show": "color","Id": "","Name": "","Mj": "","Out": "","OutGon": "","OutPon": "",
"OutFlower": "","Auto": "","AutoTin": "","AutoGon": "","AutoPon": "","Dump": ""
               ]);
mapping P3Data = ([
"Show": "color","Id": "","Name": "","Mj": "","Out": "","OutGon": "","OutPon": "",
"OutFlower": "","Auto": "","AutoTin": "","AutoGon": "","AutoPon": "","Dump": ""
               ]);
mapping P4Data = ([
"Show": "color","Id": "","Name": "","Mj": "","Out": "","OutGon": "","OutPon": "",
"OutFlower": "","Auto": "","AutoTin": "","AutoGon": "","AutoPon": "","Dump": ""
               ]);
mapping record;
void create()
{
	set_name("�±N��I",({"mj lady","lady"}));
	set("long",@LONG

�@�Ӭ��R���p�j����ۧA�L���C
	
LONG
);
        set_weight(1);
        set("race","human");
        set("gender","�k��");
        set("level",25);
        set("age",18);
        set("attitude", "friendly");
        set("unit","��");
        set("inquiry",([
           "mj": (: to_say_play :),
           "�±N": (: to_say_play :),
           "���k": (: to_say_play :),
           "play": (: to_say_play :),
           "�W�h": (: to_say_rule :),
           "rule": (: to_say_rule :),
           ]));
        setup();
        seteuid(getuid());
	if( !restore() )
        {
        	record = ([]);
        }
}

void init()
{
   add_action("do_addin","addin");
   add_action("do_dump","dump");
   add_action("do_dump","dd");
   add_action("do_eat","eat");
   add_action("do_gon","gon");
   add_action("do_win","hu");
   add_action("do_help","help");
   add_action("do_look","look");
   add_action("do_look",".");
   add_action("do_look",".1");
   add_action("do_look",".2");
   add_action("do_look",".3");
   add_action("do_look",".4");
   add_action("do_look","..");
   add_action("do_touch","mo");
   add_action("do_touch","0");
   add_action("do_pon","pon");
   add_action("do_pon","p");
   add_action("do_restart","restart");
   add_action("wash_mj","start");
   add_action("do_setmj","setmj");
   add_action("show_top","top");
   add_action("do_tin","tin");
   add_action("ch","ch");
}
int sort_user(string str1, string str2)
{
	return strcmp(str1[45..50],str2[45..50]);
}
int query_Play() { return Play; }
mapping query_record() { return record; }
int clear_record() { record=([ ]); this_object()->save(); return 1; }
int test_record(string id,int aa,int bb,int cc,int dd,int ee,int ff)
{
	record[id] = ([
		"name": id,
		"rounds" : aa,
		"self" : bb,
		"win" : cc,
		"lose" : dd,
		"total" : ee,
		"bad" : ff,
		]);
	return 1;
}
int do_addin()
{
        object me=this_player();
        if (me->query("id")==P1Data["Id"]
        ||  me->query("id")==P2Data["Id"]
        ||  me->query("id")==P3Data["Id"]
        ||  me->query("id")==P4Data["Id"]){
            if (!Playing) message_vision("$N�j��: [��}�ڡ��] �����������ڳ�.....�C\n",me);
            else message_vision("$N��ۤj�a��: ���ѦۺN"+(random(12)+1)+"���N�n�C\n",me);
            return 1;
        }
       if (Playing){
                if (random(2))
                message_vision(this_object()->name()+
                "���"+me->name()+"���G �P�����b�i�椤�Ш���䧤�@�U...�C\n",me);
                else  message_vision("$N�۵�: [�ڤ]�n���ա��] �����������ڳ�.....�C\n",me);
                return 1;
        }
        if (!P1Data["Id"] || P1Data["Id"]==""){
           P1Data["Id"]=me->query("id");
           NowPlayerId[Play]=me->query("id");
           message_vision("$N�[�J�F�o���P���C\n",me);
           Play++;
           Times=0;
           LookP+="�b�e����"+me->name()+"�A";
           return 1;
        }else if (!P2Data["Id"] || P2Data["Id"]==""){
                 P2Data["Id"]=me->query("id");
                 message_vision("$N�[�J�F�o���P���C\n",me);
                 NowPlayerId[Play]=me->query("id");
                 Play++;
                 Times=0;
                 LookP+=me->name()+"�A";
                 return 1;
        }else if (!P3Data["Id"] || P3Data["Id"]==""){
                 P3Data["Id"]=me->query("id");
                 message_vision("$N�[�J�F�o���P���C\n",me);
                 NowPlayerId[Play]=me->query("id");
                 Play++;
                 Times=0;
                 LookP+=me->name()+"�A";
                 return 1;
        }else if (!P4Data["Id"] || P4Data["Id"]==""){
                 P4Data["Id"]=me->query("id");
                 message_vision("$N�[�J�F�o���P���C\n",me);
                 NowPlayerId[Play]=me->query("id");
                 Play++;
                 Times=0;
                 LookP+=me->name();
                 return wash_mj(Play);
        }
        return notify_fail("�H�Ƥw���C\n");
}
int do_dump(string str,object me)
{
        int check,i;
        int *score=({ 0,0,0,0,0 });
        string ponid;
        mapping who;
        object met,user;
 
        if (!me) me=this_player();
        if (check_id(me->query("id"),"player")!="");
        else {
           command("stare "+me->query("id"));
           command("say �o�P����A�S���Y�C");
           return 1;
        }
        if (!Playing){
           command("kick "+me->query("id"));
           command("say �P���٨S�}�l�Ф��n���P�å�!!");
           return 1;
        }
        tell_object(me,"���֥��P:"+NowPlayerId[NowPlayer]+"\n");
        if (!str) return notify_fail("���O:dump <�N�X>\n");
        if (me->query("id")!=NowPlayerId[NowPlayer]){
           command("hammer "+me->query("id"));
           command("say �Q�����P!!�@����?");
           return 1;
        }
        if (!Touched){
           command("faint "+me->query("id"));
           command("say �A�٨S�N�P!!");
           return 1;
        }
        if (Goned==5){
           message_vision("$N���D�G�����]"+HIR+"���b�X�P"+NOR+"�ЦA���s�}�l start �C\n",this_object());
           Playing=0;
           Count++;
           if (Play>=RECORD_PLAYERS){
              for (i=0;i<Play;i++){
                  met=present(NowPlayerId[i], environment(this_object()));
                  if (!met) met=find_player(NowPlayerId[i]);
                  if (!met);
                  else{
                     score = ({ 0,0,0,0,0 });
                     set_mjdata(met,score);
                     this_object()->save();
                  }
              }
           }
           return 1;
        }
        NO_HU=0;
        HU_F=0;
        NO_GON=0;
        if (me->query("id")==P1Data["Id"]) who=P1Data;
        else if (me->query("id")==P2Data["Id"]) who=P2Data;
        else if (me->query("id")==P3Data["Id"]) who=P3Data;
        else if (me->query("id")==P4Data["Id"]) who=P4Data;
        check=do_check_Mj(MjE,str);
        if (check==0) return notify_fail("�S��["+str+"]�o�إN�X�C\n");
        check=do_check_Mj(who["Mj"],str);
        if (check==0) return notify_fail("�A�S"+do_check_num(str,0)+"�o�i�P�C\n");
        tell_object(me,"�A���D�G"+do_check_num(str,0)+"\n");
        tell_room(environment(this_object()),YEL+me->name()+"���G"+do_check_num(str,0)+"�C\n"+NOR,me);
//        command("say "+me->name()+"���X�F�@�i.."+do_check_num(str,0));
        message_vision("$N���X�F�@�i.."+do_check_num(str,3)+"\n",me);
        who["Mj"]=do_delete_Mj(who["Mj"],str,1);
        LastDump=str;
        who["Dump"]+=str;
        LastDumpId=who["Id"];
        Touched=0;
        NowPlayer++;
        NowPlayer%=Play;
        message_vision(YEL+"$N���G�ٳѤU["HIC+(end-count-16-Goned)/2+NOR+YEL+"]�i�P�i�N�A�{�b���� "+HIY+capitalize(NowPlayerId[NowPlayer])+NOR+YEL+" �N�P�C\n"+NOR,this_object());
        if(user = present(NowPlayerId[NowPlayer], environment(this_object())))
        {
        	tell_object(user,HIW+"<�ӧA�o!!>\n"+NOR);
        }
        if (Auto_Tin){
           ponid=check_id(str,"tin");
           if (ponid!=""){
              me=present(ponid, environment(this_object()));
              if (!me) me=find_player(ponid);
              if (!me) return 1;
              return do_win(str,me);
           }
        }
        if (Auto_Gon){
           ponid=check_id(str,"gon");
           if (ponid!=""){
              me=present(ponid, environment(this_object()));
              if (!me) me=find_player(ponid);
              if (!me) return 1;
              do_gon(str,me);
           }
        }
        if (Auto_Pon){
           ponid=check_id(str,"pon");
           if (ponid!=""){
              me=present(ponid, environment(this_object()));
              if (!me) me=find_player(ponid);
              if (!me) return 1;
              do_pon(str,me);
           }
        }
        if (count==(end-16-Goned)){
           Playing=0;
           Count++;
           message_vision(YEL+"$N���G����"+HIY+"�y��"+NOR+YEL+"�ЦA���s�}�l "+HIR+"start"+NOR+YEL+" �C\n"+NOR,this_object());
           str="�ҳѤU���P����:"+show_mj(List[count..end],2)+"\n";
           tell_room(environment(this_object()),str);
           if (Play>=RECORD_PLAYERS){
              for (i=0;i<Play;i++){
                  met=present(NowPlayerId[i], environment(this_object()));
                  if (!met) met=find_player(NowPlayerId[i]);
                  if (!met);
                  else{
                     score = ({ 0,0,0,0,0 });
                     set_mjdata(met,score);
                     this_object()->save();
                  }
              }
           }
           return 1;
        }
        if (Auto){
           if (NowPlayerId[NowPlayer]==P1Data["Id"]) who=P1Data;
           else if (NowPlayerId[NowPlayer]==P2Data["Id"]) who=P2Data;
           else if (NowPlayerId[NowPlayer]==P3Data["Id"]) who=P3Data;
           else if (NowPlayerId[NowPlayer]==P4Data["Id"]) who=P4Data;
           if (who["Auto"]=="auto"){
              me=present(NowPlayerId[NowPlayer], environment(this_object()));
              if (!me) me=find_player(NowPlayerId[NowPlayer]);
              if (!me) return 1;
              call_out("do_touch",1,"AUTO",me);
           }
        }
        return 1;
}
int do_eat(string str)
{
        int LastDumpMan,i;
        string num1,num2;
        object me=this_player();
        mapping who;
 
        if (!str || sscanf(str,"%s %s",num1,num2)!=2) return 0;
        if (check_id(me->query("id"),"player")!="");
        else {
           command("stare "+me->query("id"));
           command("say �o�P����A�S���Y�C");
           return 1;
        }
        if (!Playing){
           command("say �P���٨S�}�l�C");
           return 1;
        }
        tell_object(me,"���ֺN�P:"+NowPlayerId[NowPlayer]+"\n");
        if (me->query("id")!=NowPlayerId[NowPlayer]){
           command("hammer "+me->query("id"));
           command("say �٨S����A�C");
           return 1;
        }
        if (!LastDump || LastDump==""){
           command("hammer "+me->query("id"));
           command("say �N�P�a�C");
           return 1;
        }
        if (Touched){
           command("flop "+me->query("id"));
           command("say ���P��!!");
           return 1;
        }
        if (do_check_eat(num1,num2,LastDump)==0){
           command("flop "+me->name());
           command("say �A������F��!!�o�ˤ]��Y�C");
           return 1;
        }
        if (num1==num2){
           command("flop "+me->name());
           command("say �ۦP���P����Y�A�u��θI(pon)���C");
           return 1;
        }
        if (me->query("id")==P1Data["Id"]) who=P1Data;
        else if (me->query("id")==P2Data["Id"]) who=P2Data;
        else if (me->query("id")==P3Data["Id"]) who=P3Data;
        else if (me->query("id")==P4Data["Id"]) who=P4Data;
        LastDumpMan=do_check_Mj(MjE,num1);
        if (LastDumpMan==0) return notify_fail("�S��["+num1+"]�o�إN�X�C\n");
        LastDumpMan=do_check_Mj(MjE,num2);
        if (LastDumpMan==0) return notify_fail("�S��["+num2+"]�o�إN�X�C\n");
        LastDumpMan=do_check_Mj(who["Mj"],num1);
        if (LastDumpMan==0) return notify_fail("�A�S"+do_check_num(num1,0)+"�o�i�P�C\n");
        LastDumpMan=do_check_Mj(who["Mj"],num2);
        if (LastDumpMan==0) return notify_fail("�A�S"+do_check_num(num2,0)+"�o�i�P�C\n");
 message_vision(HIG+"\n�i �� �Y �� �j"+NOR+"\n$N���X�F�@�i"+do_check_num(num1,3)+
                      "�P�@�i"+do_check_num(num2,3)+
                      "�Y�U�F"+do_check_num(LastDump,3)+"�C\n\n",me);
        who["Out"]+=num2;
        who["Out"]+=LastDump;
        who["Out"]+=num1;
        who["Mj"]=do_delete_Mj(who["Mj"],num1,1);
        who["Mj"]=do_delete_Mj(who["Mj"],num2,1);
        Touched=1;
        NO_HU=1;
        NO_GON=1;
        i=0;
        if (who["Show"]=="�N�X") i=3;
        if (who["Show"]=="color") i=5;
        tell_object(me,show_mj(who["Mj"],i));
        return delete_last_dump(who["Id"]);
}
int do_gon(string str,object me)
{
        int i;
        mapping who;
 
        if (!me) me=this_player();
        if (check_id(me->query("id"),"player")!="");
        else {
           command("stare "+me->query("id"));
           command("say �o�P����A�S���Y�C");
           return 1;
        }
        if (!Playing){
           command("say �P���٨S�}�l!!");
           return 1;
        }
        if (LastDumpId==me->query("id") && !str){
           command("stare "+me->query("id"));
           command("say ���i�P�O�A�ۤv�����C");
           return 1;
        }
        if (Touched && NowPlayerId[NowPlayer]!=me->query("id")){
           command("hammer "+me->query("id"));
           command("say �O�H�S���P�A���b�C");
           return 1;
        }
        if (!str) str=LastDump;
 
        if (me->query("id")==P1Data["Id"]) who=P1Data;
        else if (me->query("id")==P2Data["Id"]) who=P2Data;
        else if (me->query("id")==P3Data["Id"]) who=P3Data;
        else if (me->query("id")==P4Data["Id"]) who=P4Data;
        if (who["Auto"]=="auto") return 1;
        i=do_check_Mj(who["Mj"],str);
        if (i==1){
           if (!Touched) return notify_fail("�A�٨S�N�P�C\n");
           i=do_check_Mj(who["OutPon"],str);
           if (!i) return notify_fail("�A�u���@�i����b�C\n");
           if (NO_GON) return notify_fail("�o�˵L�k�b�P�C\n");
              message_vision("\n$N���D�G"+HIB+"�i �� �b �� �j"+NOR+"\n\n",me);
              who["Mj"]=do_delete_Mj(who["Mj"],str,1);
              sort_data(who["OutPon"]+=str);
              str=List[end..end+1];
              end-=2;
              Goned++;
              message_vision("\n$N�q�᭱�ɤF�@�i�P�C\n\n",me);
              printf("�A�ɨ�@�i%s\n",do_check_num(str,0));
              i=0;
              if (who["Show"]=="�N�X") i=3;
              if (who["Show"]=="color") i=5;
              who["Mj"]+=str;
              check_flower(who);
              tell_object(me,show_mj(who["Mj"],i));
              Touched=1;
              return 1;
        }
        if (i < 3) return notify_fail("�A�⤤�n���T�i"+do_check_num(str,0)+"�~��b�C\n");
        if (!Touched){
           if (str!=LastDump) return notify_fail("�o�˵L�k�b�C\n");
        }
        else if (i < 4) return notify_fail("�A�⤤�n���|�i"+do_check_num(str,0)+"�~��t�b�C\n");
        for (i=0;i<Play;i++) {
            if (NowPlayerId[NowPlayer]==me->query("id")) break;
            NowPlayer++;
            NowPlayer%=Play;
        }
        who["Mj"]=do_delete_Mj(who["Mj"],str,3);
        if (Touched && NowPlayerId[NowPlayer]==me->query("id")){
           NO_HU=0;
           if(random(2)) message_vision("\n$N�y�W�S�X���c�����e���G���n�N��..�ڷt�b..hehe...\n\n",me);
           else message_vision("\n$N���L�������G�o���t�b�j���|�b���@��H�C\n\n",me);
           who["Mj"]=do_delete_Mj(who["Mj"],str,1);
           for (i=0;i<4;i++) who["Out"]+="xx";
           for (i=0;i<4;i++) who["OutGon"]+=str;
        }else{
           NO_HU=1;
           message_vision("\n$N�j�s�G"+do_check_num(str,0)+"��"+HIW+"�i �� �b �� �j"+NOR+"\n\n",me);
           for (i=0;i<4;i++) who["Out"]+=str;
        }
        str=List[end..end+1];
        end-=2;
        Goned++;
        message_vision("$N�q�᭱�ɤF�@�i�P�C\n",me);
        tell_object(me,"�A�ɨ�@�i"+do_check_num(str,0)+"\n");
        who["Mj"]+=str;
        check_flower(who);
        i=0;
        if (who["Show"]=="�N�X") i=3;
        if (who["Show"]=="color") i=5;
        tell_object(me,show_mj(who["Mj"],i));
        if (Touched) return 1;
        Touched=1;
        return delete_last_dump(who["Id"]);
}
varargs int do_win(string str,object me)
{
        int i,j;
        int *score=({0,0,0,0,0});
        string Mj="";
        mapping who;
        object met;
 
        if (!me) me=this_player();
        if (check_id(me->query("id"),"player")!="");
        else {
           command("stare "+me->query("id"));
           command("say �o�P����A�S���Y�C");
           return 1;
        }
        if (!Playing){
           command("say �P���٨S�}�l...");
           return 1;
        }
        if ( NO_HU ) return notify_fail("�o�ˤ���J�P�C\n");
        if (LastDump==""&&Touched) message_vision("\n$N�j�s�G"+HIW+"�i �� ��� �J ���j"+NOR+"\n\n",me);
        else{
             tell_room(environment(this_object()),"\n"+me->name()+"�j�s�G"+HIW+"�i �ڡ�J��ա� �j"+NOR+"\n\n",me);
             tell_object(me,"\n�A�j�s�G"+HIW+"�ڡ�J��ա�"+NOR+"\n\n");
        }
        if (Touched&&NowPlayerId[NowPlayer]==me->query("id"))
           message_vision("$N���D�G�J�a"+me->name()+HIG+"�ۺN"+NOR+"��������"+HIR+"�Y��"+NOR+"������\n",this_object());
        else if ( LastDumpId==me->query("id") ) return notify_fail("�A�n�J�A�ۤv�����P??\n");
        else command("say "+me->name()+"�J�F");
        if (me->query("id")==P1Data["Id"]) who=P1Data;
        else if (me->query("id")==P2Data["Id"]) who=P2Data;
        else if (me->query("id")==P3Data["Id"]) who=P3Data;
        else if (me->query("id")==P4Data["Id"]) who=P4Data;
        if (sizeof(who["OutFlower"]) ==16) i=1;
        else if (sizeof(who["OutFlower"]) ==14&&sizeof(P1Data["OutFlower"]+P2Data["OutFlower"]+P3Data["OutFlower"]+P4Data["OutFlower"])==16) i=1;
        if (!HU_F) i=0;
        if (i){
           Mj+="�J�a����P�O:\n";
           Mj+=show_mj(who["OutFlower"],1);
           if (NowPlayerId[NowPlayer]==who["Id"]) Mj+="�J�a��J�ۺN\n";
           else{
             if (sizeof(P1Data["OutFlower"])==2) LastDumpId=P1Data["Id"];
             else if (sizeof(P2Data["OutFlower"])==2) LastDumpId=P2Data["Id"];
             else if (sizeof(P3Data["OutFlower"])==2) LastDumpId=P3Data["Id"];
             else if (sizeof(P4Data["OutFlower"])==2) LastDumpId=P4Data["Id"];
             Mj+="\n��P��j��:"+HIB+LastDumpId+NOR+"\n";
           }
        }else{
          Mj+="�J�a���P�O:\n";
          if (who["OutGon"]!=""){
             Mj+="�t�b����:\n";
             Mj+=show_mj(who["OutGon"],0);
          }
          Mj+=who["Id"]+":�⤤���P��:\n";
          if (!Touched){
             who["Mj"]+=LastDump;
             who["Mj"]=sort_data(who["Mj"]);
             Mj+=show_mj(who["Mj"],0);
             Mj+="�ҭJ���P�O:"+HIR+do_check_num(LastDump,0)+NOR;
             Mj+="\n��j��:"+HIB+LastDumpId+NOR+"\n";
          }else{
             Mj+=show_mj(who["Mj"],0);
             if (str) Mj+="�ҦۺN���P�O:"+HIR+do_check_num(str,0)+NOR+"\n";
          }
        }
        Playing=0;
        tell_room(environment(this_object()),Mj);
        Tc="";
        if (do_check_win(who["Mj"])==1||i==1){
//��x///////////////////////////////////
        mixed MjT = ([
"@1" : ({ "���a", 1 }),"@2" : ({ "�ۺN", 1 }),"@3" : ({ "��P", 1 }),"@4" : ({ "���M", 1 }),
"@5" : ({ "�F��", 1 }),"@6" : ({ "�n��", 1 }),"@7" : ({ "�護", 1 }),"@8" : ({ "�_��", 1 }),
"@9" : ({ "����", 1 }),"@0" : ({ "�C�o", 1 }),"@a" : ({ "�ժO", 1 }),"@G" : ({ "�@�פf", 1 }),
"@b" : ({ "�����N��", 1 }),"@c" : ({ "��������", 1 }),"@d" : ({ "���J", 2 }),"@e" : ({ "�F���F", 2 }),
"@f" : ({ "�n���n", 2 }),"@g" : ({ "�護��", 2 }),"@h" : ({ "�_���_", 2 }),"@i" : ({ "���D�H", 2 }),
"@j" : ({ "�T�t��", 2 }),"@H" : ({ "�G�פf", 2 }),"@k" : ({ "�T�b�l", 2 }),"@B" : ({ "�K�L��V", 2 }),
"@C" : ({ "�������", 2 }),"@l" : ({ "���M�ۺN", 3 }),"@m" : ({ "�I�I�J", 4 }),"@n" : ({ "�V�@��", 4 }),
"@o" : ({ "�p�T��", 4 }),"@p" : ({ "�|�t��", 6 }),"@q" : ({ "�M�@��", 8 }),"@r" : ({ "�r�@��", 8 }),
"@s" : ({ "�C��l", 8 }),"@t" : ({ "�j�T��", 8 }),"@u" : ({ "���t��", 8 }),"@F" : ({ "�p�|��", 8 }),
"@D" : ({ "�C�m�@", 8 }),"@E" : ({ "��@��", 16 }),"@v" : ({ "�j�|��", 16 }),"@w" : ({ "�ѭJ", 16 }),
"@x" : ({ "�a�J", 16 }),"@y" : ({ "�H�J", 16 }),"@z" : ({ "��h�L��", 16 }),"@A" : ({ "�K�P�L��", 16 }),
"@J" : ({ "�M���Y", 8 }),"@I" : ({ "�V���Y", 4 }),
]);//H
           get_tc(who);
////////////////
           str="\t\t\t�ݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡ�\n";
           for (i=0;i<sizeof(Tc);i+=2){
              str+=sprintf("\t\t\t%-12s%8s �x\n",MjT[Tc[i..i+1]][0],chinese_number(MjT[Tc[i..i+1]][1]));
              j+=MjT[Tc[i..i+1]][1];
           }
           if (Count){
              str+=sprintf("\t\t\t%-12s%8s �x\n","�s"+chinese_number(Count)+"��"+chinese_number(Count),chinese_number(Count*2));
              j+=Count*2;
           }
           str+=sprintf("\t\t\t�򥻥x            �T �x\n\t\t\t%20s\n","�`�x��:"+chinese_number(j+3)+" �x");
           str+="\t\t\t�ݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡ�\n";
           tell_room(environment(this_player()),str);
/////////////
           if (!Touched){
              if (Play>=RECORD_PLAYERS){
		 score = ({ 0,1,0,j+3,0}); // ({ �ۺN,�J�P,��j,�x��<��j���t��>,�ǳW })
                 set_mjdata(me,score);
                 met=present(LastDumpId, environment(this_object()));
                 if (!met) met=find_player(LastDumpId);
                 if (!met);
                 else{
		    score = ({ 0,0,1,-j-3,0 });  // ({ �ۺN,�J�P,��j,�x��<��j���t��>,�ǳW })
                    set_mjdata(met,score);
                    this_object()->save();
                 }
                 for (i=0;i<Play;i++){
                     met=present(NowPlayerId[i], environment(this_object()));
                     if (!met) met=find_player(NowPlayerId[i]);
                     if (!met);
                     else{
                        score = ({ 0,0,0,0,0 });  // ({ �ۺN,�J�P,��j,�x��<��j���t��>,�ǳW })
                        set_mjdata(met,score);
                        this_object()->save();
                     }
                 }
              }
           }else{ //�ۺN
              if (Play>=RECORD_PLAYERS || this_object()->query("debug")){
		 score = ({ 1,0,0,(j+3)*(Play-1),0 });  // ({ �ۺN,�J�P,��j,�x��<��j���t��>,�ǳW })
                 set_mjdata(me,score);
                 for (i=0;i<Play;i++){
                     if (NowPlayerId[i]==me->query("id")) continue;
                     met=present(NowPlayerId[i], environment(this_object()));
                     if (!met) met=find_player(NowPlayerId[i]);
                     if (!met);
                     else{
			score = ({ 0,0,0,-j-3,0 });  // ({ �ۺN,�J�P,��j,�x��<�鬰�t��>,�ǳW })
                        set_mjdata(met,score);
                        this_object()->save();
                     } //else
                 } //for
              } // player==4
           }
         if (NowPlayerId[0]==who["Id"]) Count++;
         else{
           Times++;
           Count=0;
         }
        }else{
           command("sigh "+who["Id"]);
           message_vision(YEL+"$N���G���a ["+HIY+who["Id"]+NOR+YEL+"] "+HIR+" ���E �� �j�� ���"+NOR+YEL+"�C\n"+NOR,this_object());
           Times++;
           Count=0;
           if (Play>=RECORD_PLAYERS){
              if (NowPlayerId[NowPlayer]==who["Id"]&&Touched){
                 if (who["Out"]==""&&who["OutPon"]==""){
                    j=12;
                 }else {
                    j=9;
                 }
              }else{
                 if (who["Out"]==""&&who["OutPon"]==""){
                    j=4;
                 }else{
                    j=3;
                 }
              }
////////////////
              str="\t\t\t�ݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡ�\n";
              str+=sprintf("\t\t\t%-12s%8s �x\n","���E�j��",chinese_number(j));
              str+=sprintf("\t\t\t%20s\n","�˦��`�x��:"+chinese_number(j)+" �x");
              str+="\t\t\t�ݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡݡ�\n";
              tell_room(environment(this_player()),str);
/////////////
	      score = ({ 0,0,0,-j,1 });  // ({ �ۺN,�J�P,��j,�x��<��j���t��>,�ǳW })
              set_mjdata(me,score);
              for (i=0;i<Play;i++){
                  met=present(NowPlayerId[i], environment(this_object()));
                  if (!met) met=find_player(NowPlayerId[i]);
                  if (!met);
                  else{
              	     score = ({ 0,0,0,0,0 });  // ({ �ۺN,�J�P,��j,�x��<��j���t��>,�ǳW })
                     set_mjdata(met,score);
                     this_object()->save();
                  }
              }
           }
        }
        if(Play >= RECORD_PLAYERS)
        {
	        Mj="\n[0;1;36;46m�i";
	        for (i=0; i<26; i++) Mj+="�i";
	        Mj+="[1;36;46m��[0m\n";
	        Mj+="[1;36;46m�i[0;36m�j    "+HIW+"��[0m��W�r  [1m�w[0m������  [1m�`[0m����  [1m��[0m�N����  [1m��[0m�j����  [1m��[0m�W�����[1;36;46m�j[0m\n";
	        for (i=0;i<Play;i++){
	            Mj+=sprintf("[1;36;46m�i[0;36m�j[1;37m%12s  [33m%8d  [35m%6d  [32m%8d  [34m%8d  [34m%8d[1;36;46m�j[0m\n",
	                         NowPlayerId[i],record[NowPlayerId[i]]["rounds"],record[NowPlayerId[i]]["total"],record[NowPlayerId[i]]["self"],record[NowPlayerId[i]]["lose"],record[NowPlayerId[i]]["bad"]);
	        }
	        Mj+="[1;36;46m��";
	        for (i=0; i<26; i++) Mj+="�v";
	        Mj+="[46m�@[0m\n";
	        tell_room(environment(this_object()),Mj);
        }
        return wash_mj(Play);
}
int do_check_win(string str)
{
        int size=strlen(str),i,check;
        int t,k,W,T,S,Sp;
        string tempW="",tempT="",tempS="",tempB="";
        string Special="1w9w1s9s1t9teasowenojofaba";
 
        K=0;
        if (size > 33){
           if (do_check_Mj(str,"ea")&&do_check_Mj(str,"so")&&do_check_Mj(str,"we")&&do_check_Mj(str,"no")&&
               do_check_Mj(str,"jo")&&do_check_Mj(str,"fa")&&do_check_Mj(str,"ba")&&
               do_check_Mj(str,"1w")&&do_check_Mj(str,"9w")&&do_check_Mj(str,"1s")&&
               do_check_Mj(str,"9s")&&do_check_Mj(str,"1t")&&do_check_Mj(str,"9t")){
                  //���R��13��
                  for (i=0;i<sizeof(Special);i+=2) {
                      if (do_check_Mj(str,Special[i..i+1])){
                         str=do_delete_Mj(str,Special[i..i+1],1);
                      }
                  }
                  //�d�٦��S13�\�����P��
                  for (i=0;i<sizeof(Special);i+=2) {
                      if (do_check_Mj(str,Special[i..i+1])){
                         Sp++;
                      }
                  }
                  if (Sp==1){
                     for (i=0;i<sizeof(Special);i+=2) {
                         if (do_check_Mj(str,Special[i..i+1])){
                            str=do_delete_Mj(str,Special[i..i+1],1);
                            t++;
                          Tc+="@z";//13�\
                         }
                     }
                  }
                  else if (Sp==2){
                    for (i=0;i<sizeof(str);i+=2){
                         if (do_check_Mj(str,str[i..i+1])==2){
                            str=do_delete_Mj(str,str[i..i+1],1);
                            Sp=0;
                            t++;
                         }
                    }
                    if (Sp!=0){
                       if (str[0..1]+1==str[2..3]){
                          str=do_delete_Mj(str,str[6..7],1);
                          t++;
                       }else{
                          str=do_delete_Mj(str,str[0..1],1);
                          t++;
                       }
                    }
                  }
           }else{
              for (i=0;i<sizeof(str);i+=2){
                   if (do_check_Mj(str,str[i..i+1])==2) Sp++;
                   else if (do_check_Mj(str,str[i..i+1])==3) check++;
                   else if (do_check_Mj(str,str[i..i+1])==4) Sp++;
              }
              if (Sp==14&&check==3){
                  for (i=0;i<sizeof(str);i+=2){
                      if (do_check_Mj(str,str[i..i+1])==2){
                         str=do_delete_Mj(str,str[i..i+1],2);
                         i=-2;
                      }
                      else if (do_check_Mj(str,str[i..i+1])==4){
                              str=do_delete_Mj(str,str[i..i+1],4);
                              i=-2;
                      }
                      else if (do_check_Mj(str,str[i..i+1])==3) t++;
                  }
                  t=1;
                  Tc+="@s";//7��l
              }
           }
        }
        while(size--){
              size--;
          if (do_check_num(str[size..size+1],1) < 10) tempW+=str[size..size+1];
          else if (do_check_num(str[size..size+1],1) < 19) tempT+=str[size..size+1];
          else if (do_check_num(str[size..size+1],1) < 28) tempS+=str[size..size+1];
          else tempB+=str[size..size+1];
        }
        if (tempB!=""){
           for (i=0;i<strlen(tempB);i+=2){//
               check=do_check_Mj(tempB,tempB[i..i+1]);
               if (check==1) return 0;
               else if (check==2){
                       tempB=do_delete_Mj(tempB,tempB[i..i+1],2);
                       t++;
                       i=-2;
               }else if (check==3){
                        tempB=do_delete_Mj(tempB,tempB[i..i+1],3);
                        K++;
                        i=-2;
               }
           }//
        }
        if (tempW!="") W=check_hu(tempW);
        if (tempT!="") T=check_hu(tempT);
        if (tempS!="") S=check_hu(tempS);
        if (K==3) Tc+="@j";//�T�t��
        else if (K==4) Tc+="@p";//�|�t��
        else if (K==5) Tc+="@u";//���t��
        if (W+T+S+t==1) return 1;
        return 0;
}
int check_hu(string strW)
{
        int i,j,check;
        int k,t;
        int A,B,C,D,E,F;
        for (i=0;i<sizeof(strW);i+=2) {//�A�ⶶ�l�R��
        A=do_check_num(strW[i..i+1],2);
        B=do_check_num(strW[i+2..i+3],2);
        C=do_check_num(strW[i+4..i+5],2);
        D=do_check_num(strW[i+6..i+7],2);
        E=do_check_num(strW[i+8..i+9],2);
        F=do_check_num(strW[i+10..i+11],2);
        if (sizeof(strW) > 11 &&do_check_num(strW[i-2..i-1],2)!=A&&A+1==B&&B==C&&C+1==D&&D==E&&E+1==F
           ||do_check_num(strW[i-2..i-1],2)!=A&&A==B&&B+1==C&&C==D&&D+1==E&&E==F){
              if (A==B&&B+1==C&&C==D&&D+1==E&&E==F){
                 if (do_check_Mj(Tc,"@G")==1){
                    Tc=do_delete_Mj(Tc,"@H",1);
                    Tc+="@H";
                 }else        Tc+="@G";
              }
              for (j=0;j<6;j++) {  //�R�����l1 22 33 4 && 22 33 44
                  strW=do_delete_Mj(strW,strW[i..i+1],1);
              }
           i=-2;
        }
        else if (A+1==B&&B==C&&C==D&&D==E&&E+1==F){
              for (j=0;j<2;j++) {  //�R�����l1 2 2 2 2 3
                  strW=do_delete_Mj(strW,strW[i..i+1],1);
              }
              strW=do_delete_Mj(strW,strW[i+6..i+7],1);
           i=-2;
           }
        else if (sizeof(strW) > 9 && A+1==B&&B==C&&C==D&&D+1==E){
              //�R�����l12223����1 2 3
                  strW=do_delete_Mj(strW,strW[i..i+1],1);
                  strW=do_delete_Mj(strW,strW[i..i+1],1);
                  strW=do_delete_Mj(strW,strW[i+4..i+5],1);
           i=-2;
        }
        else if (sizeof(strW) > 9 && A==B&&B+1==C&&C+1==D&&D+1==E){
             for (j=0;j<3;j++) {   //�R�����l11234����2 3 4
                 strW=do_delete_Mj(strW,strW[i+4..i+5],1);
             }
           i=-2;
        }
        else if (sizeof(strW) > 5 && A+1==B&&B+1==C){
             for (j=0;j<3;j++) {   //�R�����l123����1 2 3
                 strW=do_delete_Mj(strW,strW[i..i+1],1);
             }
           i=-2;
        }
        }
 
        if (sizeof(strW) > 5){
           for (i=0;i<sizeof(strW);i+=2) {//�A���R��
               check=do_check_Mj(strW,strW[i..i+1]);
               if (check==3){
                  K++;
                  strW=do_delete_Mj(strW,strW[i..i+1],3);
                  i=-2;
                  }
              }
           }
           for (i=0;i<sizeof(strW);i+=2) {//�A���R��
               check=do_check_Mj(strW,strW[i..i+1]);
               if (check==2){
                  t++;
                  strW=do_delete_Mj(strW,strW[i..i+1],2);
                  i=-2;
               }
           }
           if (strW!="") return 99;
           return t;
}
int do_touch(string str,object me)
{
        int i,check;
        mapping who;
 
        if (!me) me=this_player();
        if (check_id(me->query("id"),"player")!="");
        else {
           command("stare "+me->query("id"));
           command("say �o�P����A�S���Y�C");
           return 1;
        }
        if (!Playing){
           command("say �P���٨S�}�l�A�n�N�P�h�ð_�ӣ�~~");
           return 1;
        }
        tell_object(me,"���ֺN�P:"+NowPlayerId[NowPlayer]+"\n");
        if (me->query("id")!=NowPlayerId[NowPlayer]){
           command("hammer "+me->query("id"));
           command("say �Q���P!!�S����e��~~");
           return 1;
        }
        if (Touched){
           command("flop "+me->query("id"));
           command("say ���P��!!");
           return 1;
        }
        NO_HU=0;
        NO_GON=0;
        if (me->query("id")==P1Data["Id"]) who=P1Data;
        else if (me->query("id")==P2Data["Id"]) who=P2Data;
        else if (me->query("id")==P3Data["Id"]) who=P3Data;
        else if (me->query("id")==P4Data["Id"]) who=P4Data;
        if (who["Auto"]=="auto"){
           if (str=="AUTO");
           else{
             write("�]�w�۰�ť�P��B���i�ۤv�N�P�C\n");
              return 1;
            }
        }
        Touched=1;
        str=List[count..count+1];
        count+=2;
        tell_room(environment(this_object()),me->name()+"�N�F�@�i�P�C\n",me);
        tell_object(me,"�A�N�F�@�i�P�C\n");
        tell_object(me,"�A�N��@�i.."+do_check_num(str,3)+"\n");
        if (who["Auto"]=="auto"){
           if (do_check_num(str,1) > 34){
              for (i=0;i<1;i++){
                   who["OutFlower"]+=str;
                   HU_F=1;
                   tell_room(environment(this_object()),YEL+me->name()+"���G"+HIB+"��P"+NOR+YEL+"�ɪ�!!�C\n\n"+NOR+me->name()+"���᭱�ɤF�@�i�P�C\n",me);
                   tell_object(me,"�A���G"+HIB+"��P"+NOR+"�ɪ�!!�C\n\n�A���᭱�ɤF�@�i�P�C\n");
                   str=List[end..end+1];
                   end-=2;
                   tell_object(me,"�A�N��F�@�i"+do_check_num(str,3)+"\n");
                   if (do_check_num(str,1) > 34) i--;
              }
           }
           check=do_check_Mj(who["AutoTin"],str);
           if (check!=0){
              who["Mj"]+=str;
              who["Mj"]=sort_data(who["Mj"]);
              return do_win(str,me);
           }
           call_out("do_dump",0,str,me);
        }
        who["Mj"]+=str;
        check_flower(who);
        i=0;
        if (who["Show"]=="�N�X") i=3;
        if (who["Show"]=="color") i=5;
        tell_object(me,show_mj(who["Mj"],i));
        return 1;
}
int do_pon(string str,object me)
{
        int i;
        mapping who;
 
        if (!me) me=this_player();
        if (check_id(me->query("id"),"player")!="");
        else {
           command("stare "+me->query("id"));
           command("say �o�P����A�S���Y�C");
           return 1;
        }
        if (!Playing){
           command("die "+me->query("id"));
           command("say �P���٨S�}�l!!�I�A���Y��!!");
           return 1;
        }
        if (Touched){
           command("hammer "+me->query("id"));
           command("say �O�H�S���P�A���I�C");
           return 1;
        }
        if (LastDumpId==me->query("id")){
           command("stare "+me->query("id"));
           command("say ���i�P�O�A�ۤv����!�C");
           return 1;
        }
        if (!str) str=LastDump;
        else if (str!=LastDump) return notify_fail("���i"+do_check_num(str,0)+"�w�g�L���F�C\n");
        if (me->query("id")==P1Data["Id"]) who=P1Data;
        else if (me->query("id")==P2Data["Id"]) who=P2Data;
        else if (me->query("id")==P3Data["Id"]) who=P3Data;
        else if (me->query("id")==P4Data["Id"]) who=P4Data;
        if (who["Auto"]=="auto") return 1;
        i=do_check_Mj(who["Mj"],str);
        if (i==0) return notify_fail("�A�S"+do_check_num(str,0)+"�o�i�P�n���I�C\n");
        if (i < 2) return notify_fail("�A�⤤�n����i"+do_check_num(str,0)+"�~��I�C\n");
        message_vision("\n$N�j�s�G"+do_check_num(str,0)+"��"+HIW+"�i �� �I �� �j"+NOR+"\n\n",me);
        for (i=0;i<Play;i++) {
            if (NowPlayerId[NowPlayer]==me->query("id")) break;
            NowPlayer++;
            NowPlayer%=Play;
        }
        for (i=0;i<3;i++) who["OutPon"]+=str;
        who["Mj"]=do_delete_Mj(who["Mj"],str,2);
        who["AutoPon"]=do_delete_Mj(who["AutoPon"],str,1);
        NO_HU=1;
        NO_GON=1;
        Touched=1;
        i=0;
        if (who["Show"]=="�N�X") i=3;
        if (who["Show"]=="color") i=5;
        tell_object(me,show_mj(who["Mj"],i));
        return delete_last_dump(who["Id"]);
}
//�ˬd�ثe�P���O�_���`. return 0 (�����`,�irestart) return 1(���`)
int check_player()
{
	object user;
	if(Play<2) return 0;
	else {
		if(Play > 3)
		{
			if(user = present(P4Data["Id"], environment(this_object())))
			{
				if(user->query_temp("netdead")) return 0;
				if(query_idle(user)>180) return 0;
				if(user->is_inactive()) return 0;
			}
			else return 0;
		}
		if(Play > 2)
		{
			if(user = present(P3Data["Id"], environment(this_object())))
			{
				if(user->query_temp("netdead")) return 0;
				if(query_idle(user)>180) return 0;
				if(user->is_inactive()) return 0;
			}
			else return 0;
		}
		if(user = present(P2Data["Id"], environment(this_object())))
		{
			if(user->query_temp("netdead")) return 0;
			if(query_idle(user)>180) return 0;
			if(user->is_inactive()) return 0;
		}
		else return 0;
		if(user = present(P1Data["Id"], environment(this_object())))
		{
			if(user->query_temp("netdead")) return 0;
			if(query_idle(user)>180) return 0;
			if(user->is_inactive()) return 0;
		}
		else return 0;
		
	}
	return 1;
}

int do_restart(string str)
{
        object me=this_player();
        if (me->query("id")=="guest") return 0;
        if (str!="mj"){
           if (check_id(me->query("id"),"player")!="");
           else if(!check_player());
           else 
           {
              command("stare "+me->query("id"));
              command("say �o�P����A�S���Y�C");
              return 1;
           }
        }
        message_vision("$N��P�����s�]�w�C\n",me);
        message_vision(YEL+"$N���G�P�����s�]�w�Х�"+HIR+" addin "+NOR+YEL+"�[�J�P���C\n"+NOR,this_object());
        NowPlayerId[0]="";
        NowPlayerId[1]="";
        NowPlayerId[2]="";
        NowPlayerId[3]="";
        P1Data["Id"]="";
        P2Data["Id"]="";
        P3Data["Id"]="";
        P4Data["Id"]="";
        Count=0;
        LookP ="";
        Play=START;
        Times=START;
        end=END;
        count=START;
        Playing=START;
        return 1;
}
int wash_mj(int amount)
{
        int i,x;
        string str,countstr="";
        mixed *X,MjE_Data = ([
"1w" : 0,"2w" : 0,"3w" : 0,"4w" : 0,"5w" : 0,"6w" : 0,"7w" : 0,"8w" : 0,"9w" : 0,
"1s" : 0,"2s" : 0,"3s" : 0,"4s" : 0,"5s" : 0,"6s" : 0,"7s" : 0,"8s" : 0,"9s" : 0,
"1t" : 0,"2t" : 0,"3t" : 0,"4t" : 0,"5t" : 0,"6t" : 0,"7t" : 0,"8t" : 0,"9t" : 0,
"ea" : 0,"so" : 0,"we" : 0,"no" : 0,"jo" : 0,"fa" : 0,"ba" : 0,
"f1" : 0,"f2" : 0,"f3" : 0,"f4" : 0,"f5" : 0,"f6" : 0,"f7" : 0,"f8" : 0
                            ]);
        if (!Play){
           command("say �S�����a�n�ڥլ~�P!!�����S���C");
           return 1;
        }
        if (Playing){
           command("say �P�����b�i�椤�C");
           return 1;
        }
        command("say �������~�P�A�����֭J�n�Y����..:)");
        if (Play<RECORD_PLAYERS) command("say ���a�������ĤH�ƩҥH���p���C");
        P1Data["Mj"]="";
        P1Data["OutGon"]="";
        P1Data["Out"]="";
        P1Data["OutPon"]="";
        P1Data["OutFlower"]="";
        P1Data["Auto"]="";
        P1Data["AutoTin"]="";
        P1Data["AutoGon"]="";
        P1Data["AutoPon"]="";
        P1Data["Dump"]="";
 
        P2Data["Mj"]="";
        P2Data["OutGon"]="";
        P2Data["Out"]="";
        P2Data["OutPon"]="";
        P2Data["OutFlower"]="";
        P2Data["Auto"]="";
        P2Data["AutoTin"]="";
        P2Data["AutoGon"]="";
        P2Data["AutoPon"]="";
        P2Data["Dump"]="";
 
        P3Data["Mj"]="";
        P3Data["OutGon"]="";
        P3Data["Out"]="";
        P3Data["OutPon"]="";
        P3Data["OutFlower"]="";
        P3Data["Auto"]="";
        P3Data["AutoTin"]="";
        P3Data["AutoGon"]="";
        P3Data["AutoPon"]="";
        P3Data["Dump"]="";
 
        P4Data["Mj"]="";
        P4Data["OutGon"]="";
        P4Data["Out"]="";
        P4Data["OutPon"]="";
        P4Data["OutFlower"]="";
        P4Data["Auto"]="";
        P4Data["AutoTin"]="";
        P4Data["AutoGon"]="";
        P4Data["AutoPon"]="";
        P4Data["Dump"]="";
 
        end=END;
        NO_HU=START;
        NO_GON=START;
        count=START;
        Playing=START;
        List="";
        NowPlayer=START;
        Touched=START;
        Auto=START;
        Auto_Tin=START;
        Auto_Gon=START;
        Auto_Pon=START;
        Goned=START;
        LastDump="";
        LastDumpId="";
        X = keys(MjE_Data);
        for (i=0;i<144;i++){
            x = random(sizeof(X));
            if (X[x]=="f1"||X[x]=="f2"||X[x]=="f3"||X[x]=="f4"||
                X[x]=="f5"||X[x]=="f6"||X[x]=="f7"||X[x]=="f8"){
                if (MjE_Data[X[x]] < 1){
                   MjE_Data[X[x]] = MjE_Data[X[x]] + 1;
                   List += X[x];
                } else i--;
            }else{
               if (MjE_Data[X[x]] < 4){
                  MjE_Data[X[x]] = MjE_Data[X[x]] + 1;
                  List += X[x];
               } else i--;
           }
        }
 
//        for (i=0;i<sizeof(X);i++) printf("%s=%d ",X[i],MjE_Data[X[i]]);
        message_vision("\n$N�ܧ֪����W���P��z�n�C\n\n",this_object());
        command("say ��!!�n�F�i�H�}�l�F�ӧa!!");
        if (Count) countstr="[�s��"+chinese_number(Count)+"]";
        if (!Times);
        else{
          if (Count);
          else {
            str=NowPlayerId[0];
            if (Play>1) NowPlayerId[0]=NowPlayerId[1];
            if (Play>2) NowPlayerId[1]=NowPlayerId[2];
            if (Play>3) NowPlayerId[2]=NowPlayerId[3];
            NowPlayerId[Play-1]=str;
          }
        }
        if (Times/Play == 4) Times=0;
        if (Times/Play == 3) str=HIW+"�_��"+NOR;
        if (Times/Play == 2) str=HIY+"�護"+NOR;
        if (Times/Play == 1) str=HIR+"�n��"+NOR;
        if (Times/Play == 0) str=HIG+"�F��"+NOR;
        i=Times;
        i%=Play;
        i++;
        message_vision("["+str+chinese_number(i)+"]�P���}�l:���a"+HIY+NowPlayerId[0]+HIR+countstr+NOR+"�Y�X��l"+
                       "["+HIG+chinese_number(i=3+random(16))+NOR+ "]�I�C\n",this_object());
        //���a���P�@����16��:Q
        if (Play>0) P1Data["Mj"]=List[0..31];
        if (Play>1) P2Data["Mj"]=List[32..63];
        if (Play>2) P3Data["Mj"]=List[64..95];
        if (Play>3) P4Data["Mj"]=List[96..127];
        count=(Play*2*16);
        if (Play>0) check_flower(P1Data);
        if (Play>1) check_flower(P2Data);
        if (Play>2) check_flower(P3Data);
        if (Play>3) check_flower(P4Data);
        Playing=1;
        message_vision(YEL+"$N���G���a"+HIY+NowPlayerId[0]+NOR+YEL+"�ж}���P�C\n"+NOR,this_object());
        return 1;
}
int do_setmj(string str)
{
        int check;
        string numstr;
        mapping who;
        object me=this_player();
 
        if (me->query("id")==P1Data["Id"]) who=P1Data;
        else if (me->query("id")==P2Data["Id"]) who=P2Data;
        else if (me->query("id")==P3Data["Id"]) who=P3Data;
        else if (me->query("id")==P4Data["Id"]) who=P4Data;
        else return 0;
        if (!str){
           numstr=this_object()->name()+"��ۧA��: �A�ثe���]�w��:\n";
          if (who["AutoTin"]!="") numstr+="�J��"+HIB+show_mj(who["AutoTin"],2)+NOR+"�|�۰�"+HIB+"[�J�P]"+NOR+"�C\n";
          if (who["AutoGon"]!="") numstr+="�J��"+HIY+show_mj(who["AutoGon"],2)+NOR+"�|�۰�"+HIY+"[�b�P]"+NOR+"�C\n";
          if (who["AutoPon"]!="") numstr+="�J��"+HIG+show_mj(who["AutoPon"],2)+NOR+"�|�۰�"+HIG+"[�I�P]"+NOR+"�C\n";
          if (who["Show"]=="�N�X")    numstr+="��ܤ覡��"+HIY+"[�N�X]"+NOR+"�覡�C\n";
          if (who["Show"]=="color")   numstr+="��ܤ覡��"+HIG+"[�m��]"+NOR+"�C\n";
          if (who["Auto"]=="auto")    numstr+="�A�]�w"+HIR+"[�۰�ť�P]"+NOR+"�C\n";
          if (who["AutoTin"]==""&&who["AutoGon"]==""&&who["AutoPon"]==""&&who["Show"]==""&&who["Auto"]=="") numstr+="�A�S������]�w�C\n";
           tell_room(environment(me),this_object()->name()+"�b"+me->name()+"���仡�F�@�ǸܡC\n",me);
           tell_object(me,numstr);
           return 1;
        }
        if (sscanf(str,"%s %s",str,numstr)!=2) return notify_fail("���O:setmj <tin>&<gon>&<pon> <�N�X>\n");
        if (str=="tin"){
           if (numstr=="none"){
              who["AutoTin"]="";
              return notify_fail("�A�����۰ʭJ�P�]�w�C\n");
           }
           check=do_check_Mj(MjE,numstr);
           if (check!=1) return notify_fail("�S��["+numstr+"]�o�صP�C\n");
           check=do_check_Mj(who["AutoTin"],numstr);
           if (check){
              who["AutoTin"]=do_delete_Mj(who["AutoTin"],numstr,1);
              return notify_fail("�A"+HIR+"�R���F"+NOR+"�J��"+do_check_num(numstr,0)+"�|�۰ʭJ�P���]�w�C\n");
           }
           who["AutoTin"]+=numstr;
           Auto_Tin=1;
           write("�A�]�w�J��"+do_check_num(numstr,0)+"�ɷ|�۰ʭJ�P�C\n");
           return 1;
        }
        else if (str=="gon"){
           if (numstr=="none"){
              who["AutoGon"]="";
              return notify_fail("�A�����۰ʺb�P�]�w�C\n");
           }
           check=do_check_Mj(who["Mj"],numstr);
           if (check==0) return notify_fail("�A�S"+do_check_num(numstr,0)+"�o�i�P�C\n");
           if (check < 3) return notify_fail("�A�⤤�n���T�i"+do_check_num(numstr,0)+"�~��]�w�b���P�C\n");
           check=do_check_Mj(who["AutoGon"],numstr);
           if (check){
              who["AutoGon"]=do_delete_Mj(who["AutoGon"],numstr,1);
              return notify_fail("�A"+HIR+"�R���F"+NOR+"�J��"+do_check_num(numstr,0)+"�|�۰ʺb�P���]�w�C\n");
           }
           who["AutoGon"]+=numstr;
           Auto_Gon=1;
           write("�A�]�w�J��"+do_check_num(numstr,0)+"�ɷ|�۰ʺb�P�C\n");
           return 1;
        }
        else if (str=="pon"){
           if (numstr=="none"){
              who["AutoPon"]="";
              return notify_fail("�A�����۰ʸI�P�]�w�C\n");
           }
           check=do_check_Mj(who["Mj"],numstr);
           if (check==0) return notify_fail("�A�S"+do_check_num(numstr,0)+"�o�i�P�C\n");
           if (check < 2) return notify_fail("�A�⤤�n����i"+do_check_num(numstr,0)+"�~��]�w�I���P�C\n");
           check=do_check_Mj(who["AutoPon"],numstr);
           if (check){
              who["AutoPon"]=do_delete_Mj(who["AutoPon"],numstr,1);
              return notify_fail("�A"+HIR+"�R���F"+NOR+"�J��"+do_check_num(numstr,0)+"�|�۰ʸI�P���]�w�C\n");
           }
           who["AutoPon"]+=numstr;
           Auto_Pon=1;
           write("�A�]�w�J��"+do_check_num(numstr,0)+"�ɷ|�۰ʸI�P�C\n");
           return 1;
        }
        else if (str=="show"){
           if (numstr=="none"||numstr=="1"){
              who["Show"]="";
              return notify_fail("�A������ܳ]�w�C\n");
           }
 
           if (numstr=="�N�X"||numstr=="3"){
              numstr="�N�X";
              write("�A�]�w�u��ܥN�X�C\n");
           }
           else if (numstr=="color"||numstr=="2"){
                numstr="color";
                 write("�A�]�w�m����ܡC\n");
           }
           else return 1;
           who["Show"]=numstr;
           return 1;
        }
        else if (str=="auto"){
           if (numstr=="none"){
              return notify_fail("��������۰�ť�P�A�n�O�]�w���~���۶B�J�a!!:>�C\n");
           }
           if (who["AutoTin"]=="") return notify_fail("�Х��]�w�nť���P�C\n");
           if (!Touched) return notify_fail("�Х��N�P�A�����]�w�C\n");
           if (numstr=="tin") write("�A�]�w�۰�ť�P�C\n");
           else return 1;
           message_vision("\n$N�j�s�@�n�G"+HIW+"��ť�ա���"+NOR+"\n\n",me);
           Auto=1;
           who["Auto"]="auto";
           return 1;
        }
        else return notify_fail("�S���o�س]�w�C\n");
}
int do_check_eat(string num1,string num2,string LastDump)
{
        int A,B,C;
        A=do_check_num(num1,1);
        B=do_check_num(num2,1);
        C=do_check_num(LastDump,1);
        if (A<10){
           if (B>10||C>10) return 0;
        }
        else if (A<19&&A>10){
                if (B>19||C>19&&B<10||C<10) return 0;
        }
        else if (A<28&&A>19){
                if (B<19||C<19) return 0;
        }
        A=do_check_num(num1,2);
        B=do_check_num(num2,2);
        C=do_check_num(LastDump,2);
 
        if (A > 9 || B > 9 || C > 9) return 0;
        if ((A+B)%2!=0){
           if (A > B){
               if (C==(A+1) || C==(A-2)) return 1;
           }else{
               if (C==(B+1) || C==(B-2)) return 1;
           }
           return 0;
        }else{
            if (A > B){
              if (C==(A-1) || C==(B+1)) return 1;
             }else{
              if (C==(B-1) || C==(A+1)) return 1;
             }
            return 0;
        }
}
string show_mj(string str,int flag)
{
        string Mj="",Mj1="";
        int size=strlen(str)+2,a,b;
        if (!str||str=="") return "";
        if (flag!=3)
        {
           if (flag==2)
           {
           	while(size--){
              		size--;
             		Mj+=do_check_num(str[size..size+1],3)+".";
           	}
           	Mj1=Mj;
           }
           else{
 	     while(size--){
                size--;
                Mj+=do_check_num(str[size..size+1],0);
             }
             size=strlen(Mj);
             Mj1="�z";
             for (a=0;a<(size/2)-1;a++){
                 if (a%2==0) Mj1+="�w";
                 else Mj1+="�s";
             }
             Mj1+="�{\n�x";
 
             for (a=0;a<size-1;a++){
                 if (flag==5 || flag==6){
                    if (Mj[a+2..a+3]=="�U") Mj1+=HIR;
                    else if (Mj[a+2..a+3]=="��") Mj1+=HIC;
                    else if (Mj[a+2..a+3]=="��") Mj1+=HIG;
                    else if (Mj[a+2..a+3]=="��") Mj1+=HIM;
                    else if (Mj[a+2..a+3]=="��") Mj1+=HIR;
                    else if (Mj[a+2..a+3]=="�o") Mj1+=HIG;
                    else if (Mj[a+2..a+3]=="�O") Mj1+=HIW;
                    else if (Mj[a+2..a+3]=="�K"
                         ||  Mj[a+2..a+3]=="�L"
                         ||  Mj[a+2..a+3]=="��"
                         ||  Mj[a+2..a+3]=="�V") Mj1+=HIR;
                    else if (Mj[a+2..a+3]=="��"
                         ||  Mj[a+2..a+3]=="��"
                         ||  Mj[a+2..a+3]=="��"
                         ||  Mj[a+2..a+3]=="��") Mj1+="[1;30m";
                 }
                 Mj1+=Mj[a..a+1];
                 a++;a++;a++;
                 Mj1+=NOR+"�x";
             }
             Mj1+="\n�x";
             for (a=2;a<size;a++){
                 if (flag==5 || flag==6){
                         if (Mj[a..a+1]=="�U") Mj1+=RED;
                    else if (Mj[a..a+1]=="��") Mj1+=GRN;
                    else if (Mj[a..a+1]=="��") Mj1+=CYN;
                    else if (Mj[a..a+1]=="��") Mj1+=MAG;
                    else if (Mj[a..a+1]=="��") Mj1+=HIR;
                    else if (Mj[a..a+1]=="�o") Mj1+=HIG;
                    else if (Mj[a..a+1]=="��") Mj1+=HIW;
                    else if (Mj[a..a+1]=="�K") Mj1+=HIG;
                    else if (Mj[a..a+1]=="�L") Mj1+=HIB;
                    else if (Mj[a..a+1]=="��") Mj1+=HIY;
                    else if (Mj[a..a+1]=="�V") Mj1+=HIW;
                    else if (Mj[a..a+1]=="��") Mj1+=HIW;
                    else if (Mj[a..a+1]=="��") Mj1+=HIR;
                    else if (Mj[a..a+1]=="��") Mj1+=HIG;
                    else if (Mj[a..a+1]=="��") Mj1+=HIY;
                 }
                 Mj1+=Mj[a..a+1];
                 a++;a++;a++;
                 Mj1+=NOR+"�x";
             }
             Mj1+="\n�|";
             for (a=(size/2)-1;a>0;a--){
                 if (a%2!=0){
                    if (flag==0 || flag==5) Mj1+=str[a-1..a];
                    else Mj1+="�w";
                 }
                 else Mj1+="�r";
             }
             Mj1+="�}\n";
           }
           return Mj1;
        }else{
            size*=2;
            for (a=(size/2)-1;a>0;a--){
                if (a%2!=0) Mj1+=str[a-1..a];
                else Mj1+=" ";
           }
           Mj1+="\n";
        }
        return Mj1;
}
string check_id(string str,string kind)
{
        int check,i;
        if (!str) return "";
        if (kind=="tin"){
           check=NowPlayer;
           for (i=0;i<Play-1;i++) {
           if (NowPlayerId[check]==P1Data["Id"] && do_check_Mj(P1Data["AutoTin"],str)!=0) return P1Data["Id"];
           if (NowPlayerId[check]==P2Data["Id"] && do_check_Mj(P2Data["AutoTin"],str)!=0) return P2Data["Id"];
           if (NowPlayerId[check]==P3Data["Id"] && do_check_Mj(P3Data["AutoTin"],str)!=0) return P3Data["Id"];
           if (NowPlayerId[check]==P4Data["Id"] && do_check_Mj(P4Data["AutoTin"],str)!=0) return P4Data["Id"];
               check++;
               check%=Play;
           }
           return "";
        }
        if (kind=="gon"){
           check=do_check_Mj(P1Data["AutoGon"],str);
           if (check!=0){
              check=do_check_Mj(P1Data["Mj"],str);
              if (check < 3) return "";
              else return P1Data["Id"];
           }
           check=do_check_Mj(P2Data["AutoGon"],str);
           if (check!=0){
              check=do_check_Mj(P2Data["Mj"],str);
              if (check < 3) return "";
              else return P2Data["Id"];
           }
           check=do_check_Mj(P3Data["AutoGon"],str);
           if (check!=0){
              check=do_check_Mj(P3Data["Mj"],str);
              if (check < 3) return "";
              else return P3Data["Id"];
           }
           check=do_check_Mj(P4Data["AutoGon"],str);
           if (check!=0){
              check=do_check_Mj(P4Data["Mj"],str);
              if (check < 3) return "";
              else return P4Data["Id"];
           }
           return "";
        }
        if (kind=="pon"){
           check=do_check_Mj(P1Data["AutoPon"],str);
           if (check!=0){
              check=do_check_Mj(P1Data["Mj"],str);
              if (check < 2) return "";
              else return P1Data["Id"];
           }
           check=do_check_Mj(P2Data["AutoPon"],str);
           if (check!=0){
              check=do_check_Mj(P2Data["Mj"],str);
              if (check < 2) return "";
              else return P2Data["Id"];
           }
           check=do_check_Mj(P3Data["AutoPon"],str);
           if (check!=0){
              check=do_check_Mj(P3Data["Mj"],str);
              if (check < 2) return "";
              else return P3Data["Id"];
           }
           check=do_check_Mj(P4Data["AutoPon"],str);
           if (check!=0){
              check=do_check_Mj(P4Data["Mj"],str);
              if (check < 2) return "";
              else return P4Data["Id"];
           }
           return "";
        }
        if (kind=="player"){
           for (i=0;i<Play;i++) {
               if (NowPlayerId[i]==str) check=1;
           }
        if (check) return "Y";
        return "";
        }
}
int delete_last_dump(string whoId)
{
        mapping who;
        if (LastDumpId==P1Data["Id"]) who=P1Data;
        else if (LastDumpId==P2Data["Id"]) who=P2Data;
        else if (LastDumpId==P3Data["Id"]) who=P3Data;
        else if (LastDumpId==P4Data["Id"]) who=P4Data;
        if (who["Dump"]!="") who["Dump"]=do_delete_Mj(who["Dump"],LastDump,1);
        return 1;
}
//��^��r�ର�N�X or ���� flag 1 �N�O�ର�N�X flag 2 �ର1..9,flag 3 ������[�W�C��
mixed do_check_num(string str,int flag)
{
        int number;
 
        if (!str) return MjC[0];
        sscanf(str,"%d%s",number,str);
        if (number == 0){
        if (str=="ea") number=28;
        else if (str=="so") number=29;
        else if (str=="we") number=30;
        else if (str=="no") number=31;
        else if (str=="jo") number=32;
        else if (str=="fa") number=33;
        else if (str=="ba") number=34;
        else if (str=="f1") number=35;
        else if (str=="f2") number=36;
        else if (str=="f3") number=37;
        else if (str=="f4") number=38;
        else if (str=="f5") number=39;
        else if (str=="f6") number=40;
        else if (str=="f7") number=41;
        else if (str=="f8") number=42;
        else if (str=="xx") number=43;
        }else{
          if (str=="w") number=0+number;
          else if (str=="t") number=9+number;
          else if (str=="s") number=18+number;
          if (flag==2){
             number%=9;
             if (number==0) number=9;
          }
        }
        if (!flag) return MjC[number];
        else if(flag==3) {
        	if(str=="w") return HIR+MjC[number]+NOR;
        	else if(str=="t") return HIC+MjC[number]+NOR;
        	else if(str=="s") return HIG+MjC[number]+NOR;
        	else return HIM+MjC[number]+NOR;
        }
        else return number;
}
void check_flower(mapping who)
{
        string newstr = "",str=who["Mj"],temp,temp1;
        int i = strlen(str),j;
 
        while(i--){
              i--;
           temp=str[i..i+1];
           if (temp=="f1"||temp=="f2"||temp=="f3"||temp=="f4"||
               temp=="f5"||temp=="f6"||temp=="f7"||temp=="f8"){
              if (Playing){
                 tell_room(environment(this_object()),YEL+this_player()->name()+"���G"+HIB+"��P"+NOR+YEL+"�ɪ�!!�C\n\n"+NOR+this_player()->name()+"���᭱�ɤF�@�i�P�C\n",this_player());
                 tell_object(this_player(),"�A���D�G"+HIB+"��P"+NOR+"�ɪ�!!�C\n\n�A���᭱�ɤF�@�i�P�C\n");
                 tell_object(this_player(),"�A�N��F�@�i"+do_check_num(List[end..end+1],0)+"\n");
              }
              HU_F=1;
              who["OutFlower"]+=temp;
              str[i..i+1]=List[end..end+1];
              end-=2;
              i+=2;
              continue;
           }
           else newstr+=temp;
        }
        who["Mj"]=sort_data(newstr);
}
int do_check_Mj(string datastr,string str)
{
        int size=strlen(datastr),check=0;
 
        while(size--){
              size--;
          if (datastr[size..size+1]==str) check++;
        }
        return check;
}
string do_delete_Mj(string datastr,string str,int amount)//��Y�P�h��
{
        int size=strlen(datastr),check;
        string temp="";
 
        while(size--){
              size--;
          if (datastr[size..size+1]==str && amount!=0) amount--;
          else temp+=datastr[size..size+1];
        }
        size=strlen(temp);
        datastr=temp;
        temp="";
        while(size--){
              size--;
              temp+=datastr[size..size+1];
        }
        return temp;
}
string sort_data(string str)
{
        int i = strlen(str),a,b,c,d;
 
        string newstr="",temp="";
        for (a=-1;a<i;a++){
            a++;
            for (b=a+2;b<i;b++){
                b++;
                c=do_check_num(str[a..a+1],1);
                d=do_check_num(str[b-1..b],1);
                if (c < d){
                   temp=str[a..a+1];
                   str[a..a+1]=str[b-1..b];
                   str[b-1..b]=temp;
                }
            }
        }
        return str;
}
int do_look(string arg)
{
        int i,l;
        object me=this_player();
        string Mj="",p1o="",p2o="",p3o="",p4o="",verb;
        mapping who;
 	verb = query_verb();
        if (verb==".")  arg="mj";
        if (verb=="..") arg="chicken";
        if (verb==".1") arg="1p";
        if (verb==".2") arg="2p";
        if (verb==".3") arg="3p";
        if (verb==".4") arg="4p";
        if (verb==".0") arg="all";
        if (me->query("id")==P1Data["Id"]) who=P1Data;
        else if (me->query("id")==P2Data["Id"]) who=P2Data;
        else if (me->query("id")==P3Data["Id"]) who=P3Data;
        else if (me->query("id")==P4Data["Id"]) who=P4Data;
        else return 0;
        if (who["Auto"]=="auto") l=1;
        if (arg=="1p"||arg=="2p"||arg=="3p"||arg=="4p"||arg=="all"||arg=="chicken"||arg=="end"||arg=="dump"||arg=="mj");
        else return 0;
        if (arg=="1p") who=P1Data;
        if (arg=="2p") who=P2Data;
        if (arg=="3p") who=P3Data;
        if (arg=="4p") who=P4Data;
        if (arg=="1p"||arg=="2p"||arg=="3p"||arg=="4p"){
           i=0;
           if (who["Show"]=="�N�X") i=3;
           if (who["Show"]=="color") i=5;
           if (!Playing||check_id(me->query("id"),"player")==""||l==1){
              if (who["OutGon"]!=""){
                 Mj+=who["Id"]+":�t�b���P��:\n";
                 Mj+=show_mj(who["OutGon"],i+1);
              }
              Mj+=who["Id"]+":�⤤���P��:\n";
              Mj+=show_mj(who["Mj"],i);
           }
           Mj+=who["Id"]+":�\\�b�~�����P��:\n";
           Mj+=show_mj(who["Out"]+who["OutPon"]+who["OutFlower"],i+1);
           Mj+=who["Id"]+":���L���P:\n";
           Mj+=show_mj(who["Dump"],2);
        }
        else if (arg=="mj") {
           if (!Playing) return 0;
           if (who["OutGon"]!=""){
              Mj+="�A���t�b���P��:\n";
              Mj+=show_mj(who["OutGon"],1);
           }
           if (who["Show"]=="�N�X") i=3;
           if (who["Show"]=="color") i=5;
           Mj+="�A�\\�b�~�����P��:\n";
           Mj+=show_mj(who["Out"]+who["OutPon"]+who["OutFlower"],i+1);
           Mj+="�A�⤤���P��:\n";
           Mj+=show_mj(who["Mj"],i);
           Mj+="�A���]�w��:";
        }else if (arg=="all") {
              i=0;
              if (who["Show"]=="�N�X") i=3;
              if (who["Show"]=="color") i=5;
              Mj+=P1Data["Id"]+":�\\�b�~�����P��:\n";
              Mj+=show_mj(P1Data["Out"]+P1Data["OutPon"]+P1Data["OutFlower"],i+1);
              Mj+=P1Data["Id"]+":���L���P��:\n";
              Mj+=show_mj(P1Data["Dump"],2)+"\n";
              Mj+=P2Data["Id"]+":�\\�b�~�����P��:\n";
              Mj+=show_mj(P2Data["Out"]+P2Data["OutPon"]+P2Data["OutFlower"],i+1);
              Mj+=P2Data["Id"]+":���L���P��:\n";
              Mj+=show_mj(P2Data["Dump"],2)+"\n";
              Mj+=P3Data["Id"]+":�\\�b�~�����P��:\n";
              Mj+=show_mj(P3Data["Out"]+P3Data["OutPon"]+P3Data["OutFlower"],i+1);
              Mj+=P3Data["Id"]+":���L���P��:\n";
              Mj+=show_mj(P3Data["Dump"],2)+"\n";
              Mj+=P4Data["Id"]+":�\\�b�~�����P��:\n";
              Mj+=show_mj(P4Data["Out"]+P4Data["OutPon"]+P4Data["OutFlower"],i+1);
              Mj+=P4Data["Id"]+":���L���P��:\n";
              Mj+=show_mj(P4Data["Dump"],2)+"\n";
        }else if (arg=="chicken"){
                 if (Playing){
                    Mj=LookP+"���{�u���b���P\n";
                    Mj+="�ٳѤU"+sprintf("%d",(end-count-16-Goned)/2)+"���P�N�y���F�C\n";
                    if (LastDump!="") Mj+=LastDumpId+"��襴�X�F"+show_mj(LastDump,2)+"\n";
                    if (Count) Mj+=NowPlayerId[0]+":�s��"+chinese_number(Count)+"\n";
                    if (P1Data["Out"]=="" && P1Data["OutPon"]=="") p1o=HIY+"���M"+NOR;
                    if (P2Data["Out"]=="" && P2Data["OutPon"]=="") p2o=HIY+"���M"+NOR;
                    if (P3Data["Out"]=="" && P3Data["OutPon"]=="") p3o=HIY+"���M"+NOR;
                    if (P4Data["Out"]=="" && P4Data["OutPon"]=="") p4o=HIY+"���M"+NOR;
                    Mj+="1.�F�a�O:"+NowPlayerId[0]+p1o+"\n2.�n�a�O:"+NowPlayerId[1]+p2o+"\n";
                    Mj+="3.��a�O:"+NowPlayerId[2]+p3o+"\n4.�_�a�O:"+NowPlayerId[3]+p4o+"\n";
                 }
                 else if (NowPlayerId[0]!="") Mj=LookP+"���b���H���P";
                 else Mj=LookP+"�@���±N�������H�[�J(addin)�P���C";
        }else if (arg=="end"){
           Mj+="�٦�"+chinese_number((end-count-16-Goned)/2)+"���P�N�y���F\n";
        }else if (arg=="dump"){
           Mj+=LastDumpId+"��襴�X�F"+show_mj(LastDump,2)+"\n";
        }
        else return 0;
        if (arg=="mj"){
          if (who["AutoTin"]!="") Mj+="�J��"+show_mj(who["AutoTin"],2)+"�|�۰ʭJ�P�B";
          if (who["AutoGon"]!="") Mj+="�J��"+show_mj(who["AutoGon"],2)+"�|�۰ʺb�P�B";
          if (who["AutoPon"]!="") Mj+="�J��"+show_mj(who["AutoPon"],2)+"�|�۰ʸI�P�C";
          if (who["Show"]=="�N�X")    Mj+="��ܤ覡���N�X�覡�C";
          if (who["Show"]=="color")   Mj+="��ܤ覡���m��C";
          if (who["Auto"]=="auto")    Mj+="�A�]�w�۰�ť�P�C";
          if (who["AutoTin"]==""&&who["AutoGon"]==""&&who["AutoPon"]==""&&who["Show"]==""&&who["Auto"]=="") Mj+="�A�S������]�w�C\n";
        }
        printf("%s\n",Mj);
        return 1;
}
int do_tin(string str)
{
write(@HELP_TIN

�Шϥ� setmj �ӳ]�w�۰�ť�P�C
--------------------------------------------------------------------
1: setmj tin 1w        �]�w�|�۰ʭJ�@�U(1w)�C
2: setmj auto tin      �]�w�۰�ť�P�C
3: setmj tin none      �����|�۰ʭJ�P�]�w�C

�d��:
     �N�P����o�{�����T�U����i�Hť�G�U�Τ��U�A�۰�ť�P�B�J�p�U:
     1. setmj tin 2w     (�]�wť�G�U)
     2. setmj tin 5w     (�]�wť���U)
     3. setmj auto tin   (�]�w�۰ʺN��)
     4. dump 3w          (�����o�P�}�l�۰�ť�P)
     
   <PS. �p�G�]�w�������F, �Х� setmj tin none ���s�]�w�nť���P�C>

   �Q�d�ߧ�ԲӪ�setmj �Ϊk�Х� help setmj �C
--------------------------------------------------------------------
HELP_TIN);
        return 1;
}
int do_help(string str)
{
        if (str=="setmj"){
write(@HELP
                       ��  ��  �]  �w
            setmj �i�Ϊ����۰ʭJ�B�b�B�I�Bť�B�㦡��k�C
--------------------------------------------------------------------
�Ҥl1: setmj pon 1w        �]�w�|�۰ʸI1w ��O�H���X�@�U�ɷ|�۰ʸI�@�U�C
       setmj gon 1w                                         �۰ʺb�@�U�C
       setmj tin 1w        (�i�h���]�w�H�K�J�h�ӵP)         �۰ʭJ�@�U�C
�Ҥl2: setmj show �N�X     �]�w���u��ܥN�X�C
       setmj show color    �]�w���m����ܡC
�Ҥl3: setmj tin none      �����|�۰ʭJ�P�]�w�C
       setmj gon none
       setmj pon none
�Ҥl4: setmj auto tin      �]�w�۰�ť�P�C
--------------------------------------------------------------------
HELP);
        return 1;
        }
        return 0;
}
int to_say_play()
{
write(@HELP
        ��  �O    ��          �l                             ��    ��
    �z�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�{
    �x  addin     ----------                                 �[�J�Ƨ� �x
    �x  look      l mj��.�ݦۤv�P,l 1p��.1�ݪ��a1���P                 �x
    �x            l all��..�ݥ���,l end�ݬy��l dump�C        �ݵP     �x
    �x  mo(0)     ----------                                 �N�P     �x
    �x  dump(dd)  dump <�N�X>�C                              ���P     �x
    �x  eat       eat <�N�X1> <�N�X2>�C                      �Y�P     �x
    �x  pon(p)    ----------                                 �I�P     �x
    �x  gon       gon �� gon <�N�X>(�t�b��)�C                �b�P     �x
    �x  hu                                                   �J�P     �x
    �x  setmj     help setmj�C                               �]�w�Ѽ� �x
    �x  start     ----------                                 �P���}�l �x
    �x  restart   restart �� restart mj�C                    ���s�}�l �x
    �x  top       top                                        �d���   �x
    �|�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�}
HELP);
        return 1;
}
int to_say_rule()
{
write(@HELP
 
�@�@�C�J�N�����x���A�b�[�W�ұo���x�N�O�`�x�A�n�O�ۺN�N�����A�۷��T�@����k�C
��j�N���`���Z�������ҥ����x�ơC�J�̫h�[�W�h�C
 
HELP);
        return 1;
}
int show_top(string str)
{
        string output="",*user_data=({}),*record_key=({""});
        int i;
        object me;
        me=this_player();
        if (sizeof(record) < 1)
           return notify_fail("�ثe�S�����Z�O���C\n");
	record_key = keys(record);
	for(i=0;i<sizeof(record_key);i++)
	{       // [0..23]name [25..28]rounds [30..33]self [35..38]win [40..43]lose [45..50]total [52..55]bad
		user_data+=({sprintf("%-24s %4d %4d %4d %4d %6d %4d",
			record[record_key[i]]["name"],
			record[record_key[i]]["rounds"],
			record[record_key[i]]["self"],
			record[record_key[i]]["win"],
			record[record_key[i]]["lose"],
			record[record_key[i]]["total"],
			record[record_key[i]]["bad"]
			)});
	}
	user_data = sort_array(user_data, "sort_user", this_object());
	output  = "       ��    �a           ���� �ۺN �J�P ��j ���Z�� �ǳW\n";
	output += "========================= ==== ==== ==== ==== ====== ====\n";
	for(i=0;i<sizeof(user_data);i++)
		output+=user_data[i]+"\n";
	me->start_more(output);
	return 1;
//	else return notify_fail("���Z�O�����b�ק襤�C\n");
	
}
// score �榡: ({ 0�ۺN,1�J�P,2��j,3�x��<��j���t��>,4�ǳW })
int set_mjdata(object me,int *score)
{
	if(!me ) return 0;
	message_vision("$N�ߨ�N$n�����Z�O���U�ӡC\n",this_object(),me);
	if(undefinedp(record[getuid(me)]))
	{
		record[getuid(me)] = ([
		"name": me->name_id(1),
		"rounds" : 1,
		"self" : score[0],
		"win" : score[1],
		"lose" : score[2],
		"total" : score[3],
		"bad" : score[4],
		]);
	}
	else
	{
		record[getuid(me)]["rounds"]++;
		record[getuid(me)]["self"]+=score[0];
		record[getuid(me)]["win"]+=score[1];
		record[getuid(me)]["lose"]+=score[2];
		record[getuid(me)]["total"]+=score[3];
		record[getuid(me)]["bad"]+=score[4];
		
	}
        return 1;
}

int get_tc(mapping who)
{
        int size,i,check;
        string str,tempW="",tempT="",tempS="",tempB="";
        str=who["Mj"]+who["Out"]+who["OutPon"]+who["OutGon"];
        //���a
        if (NowPlayerId[0]==who["Id"]) Tc+="@1";
        //���M&�ۺN
        if (who["Out"]==""&&who["OutPon"]==""&&Touched) Tc+="@l";
        else if (who["Out"]==""&&who["OutPon"]=="") Tc+="@4";
        else if (Touched) Tc+="@2";
        //���D�H
        if (strlen(who["Mj"]) < 5) Tc+="@i";
        size=strlen(str);
        while(size--){
              size--;
          if (do_check_num(str[size..size+1],1) < 10) tempW+=str[size..size+1];
          else if (do_check_num(str[size..size+1],1) < 19) tempT+=str[size..size+1];
          else if (do_check_num(str[size..size+1],1) < 28) tempS+=str[size..size+1];
          else tempB+=str[size..size+1];
        }
        //���P
        if (Times/Play == 0 && NowPlayerId[0]==who["Id"]&&do_check_Mj(tempB,"ea")>2) Tc+="@e";
        else if (Times/Play == 0 && do_check_Mj(tempB,"ea") > 2
             ||  NowPlayerId[0]==who["Id"]&&do_check_Mj(tempB,"ea")>2) Tc+="@5";
        if (Times/Play == 1 &&NowPlayerId[1]==who["Id"]&&do_check_Mj(tempB,"so")>2) Tc+="@f";
        else if (Times/Play == 1 && do_check_Mj(tempB,"so") > 2
             ||  NowPlayerId[1]==who["Id"]&&do_check_Mj(tempB,"so")>2) Tc+="@6";
        if (Times/Play == 2 &&NowPlayerId[2]==who["Id"]&&do_check_Mj(tempB,"we")>2) Tc+="@g";
        else if (Times/Play == 2 && do_check_Mj(tempB,"we") > 2
             ||  NowPlayerId[2]==who["Id"]&&do_check_Mj(tempB,"we")>2) Tc+="@7";
        if (Times/Play == 3 && NowPlayerId[3]==who["Id"]&&do_check_Mj(tempB,"no")>2) Tc+="@h";
        else if (Times/Play == 3 && do_check_Mj(tempB,"no") > 2
             ||  NowPlayerId[3]==who["Id"]&&do_check_Mj(tempB,"no")>2) Tc+="@8";
        //��P
        if (sizeof(who["OutFlower"]) ==16) Tc+="@A";//�K�P�L��
        else if (sizeof(who["OutFlower"]) ==14&&sizeof(P1Data["OutFlower"]+P2Data["OutFlower"]+P3Data["OutFlower"]+P4Data["OutFlower"])==16) Tc+="@D";//�C�m�@
        else if (do_check_Mj(who["OutFlower"],"f1")==1&&do_check_Mj(who["OutFlower"],"f2")==1
        &&  do_check_Mj(who["OutFlower"],"f3")==1&&do_check_Mj(who["OutFlower"],"f4")==1) Tc+="@B";//�K�L��V
        else if (do_check_Mj(who["OutFlower"],"f5")==1&&do_check_Mj(who["OutFlower"],"f6")==1
        &&  do_check_Mj(who["OutFlower"],"f7")==1&&do_check_Mj(who["OutFlower"],"f8")==1) Tc+="@C";//�������
        else if (NowPlayerId[0]==who["Id"]&&do_check_Mj(who["OutFlower"],"f1")==1
        ||  NowPlayerId[0]==who["Id"]&&do_check_Mj(who["OutFlower"],"f5")==1
        ||  NowPlayerId[1]==who["Id"]&&do_check_Mj(who["OutFlower"],"f2")==1
        ||  NowPlayerId[1]==who["Id"]&&do_check_Mj(who["OutFlower"],"f6")==1
        ||  NowPlayerId[2]==who["Id"]&&do_check_Mj(who["OutFlower"],"f3")==1
        ||  NowPlayerId[2]==who["Id"]&&do_check_Mj(who["OutFlower"],"f7")==1
        ||  NowPlayerId[3]==who["Id"]&&do_check_Mj(who["OutFlower"],"f4")==1
        ||  NowPlayerId[3]==who["Id"]&&do_check_Mj(who["OutFlower"],"f8")==1) Tc+="@3";
        //�M�@���r�@��
        if (tempW!=""&&tempT==""&&tempS==""&&tempB=="") Tc+="@q";
        else if (tempW==""&&tempT!=""&&tempS==""&&tempB=="") Tc+="@q";
        else if (tempW==""&&tempT==""&&tempS!=""&&tempB=="") Tc+="@q";
        else if (tempW==""&&tempT==""&&tempS==""&&tempB!="") Tc+="@r";
        //�V�@��
        if (tempW!=""&&tempT==""&&tempS==""&&tempB!="") Tc+="@n";
        else if (tempW==""&&tempT!=""&&tempS==""&&tempB!="") Tc+="@n";
        //��@��
        else if (tempW==""&&tempT==""&&tempS!=""&&tempB!=""){
             if (do_check_Mj(tempB,"fa")==3&&sizeof(tempB)==6
             ||  do_check_Mj(tempB,"fa")==2&&sizeof(tempB)==4
             && do_check_Mj(tempS,"1s")==0&& do_check_Mj(tempS,"5s")==0
             && do_check_Mj(tempS,"7s")==0&& do_check_Mj(tempS,"9s")==0) Tc+="@E";
             else Tc+="@n";
        }
        //�j�T��
        if (do_check_Mj(tempB,"jo") > 2
        &&  do_check_Mj(tempB,"fa") > 2
        &&  do_check_Mj(tempB,"ba") > 2) Tc+="@t";
        //�p�T��
        else if (do_check_Mj(tempB,"jo") > 1
        &&  do_check_Mj(tempB,"fa") > 1
        &&  do_check_Mj(tempB,"ba") > 1) Tc+="@o";
        else if (do_check_Mj(tempB,"jo") > 2) Tc+="@9";
        else if (do_check_Mj(tempB,"fa") > 2) Tc+="@0";
        else if (do_check_Mj(tempB,"ba") > 2) Tc+="@a";
        //�j�|��
        if (do_check_Mj(tempB,"ea") > 2
        &&  do_check_Mj(tempB,"so") > 2
        &&  do_check_Mj(tempB,"we") > 2
        &&  do_check_Mj(tempB,"no") > 2) Tc+="@v";
        //�p�|��
        else if (do_check_Mj(tempB,"ea") > 1
        &&  do_check_Mj(tempB,"so") > 1
        &&  do_check_Mj(tempB,"we") > 1
        &&  do_check_Mj(tempB,"no") > 1) Tc+="@F";
 
        for (i=0;i<sizeof(str);i+=2){
            if (str[i..i+1]=="xx") continue;
            if (do_check_Mj(str,str[i..i+1])==3) check++;
            else if (do_check_Mj(str,str[i..i+1])==4) check++;
        }
        //�I�I�J
        if (check>14){
           if (who["Out"]==""&&who["OutPon"]==""&&do_check_Mj(Tc,"@u")==0) Tc+="@m@u";
           else  Tc+="@m";
        }
        check=0;
        for (i=0;i<sizeof(str);i+=2){
            if (do_check_num(str[i..i+1],1)!=1&&do_check_num(str[i..i+1],1)>8) check++;

        }
        if (check=0&&tempB!="") Tc+="@I";//�V���Y
        else if (check=0&&tempB="") Tc+="@J";//�M���Y
        //���J
        if (tempB==""&&who["OutFlower"]==""&&check==0&&sizeof(who["AutoTin"])>3) Tc+="@d";
        //�e���N��
        if (count==((end-16-(Goned*2))-2)&&Touched) Tc+="@b";
        //����
        if (count==((end-16-(Goned*2))-2)&&!Touched) Tc+="@c";
        //�ѭJ
        if (LastDump==""&&count==(Play*2*16)+2) Tc+="@w";
        //�a�J&�H�J
        printf("%d > %d\n",count,((Play*2*16)+(Play*2)));
        if (count < ((Play*2*16)+(Play*2))
        &&P1Data["Out"]==""&&P1Data["PonOut"]==""
        &&P2Data["Out"]==""&&P2Data["PonOut"]==""
        &&P3Data["Out"]==""&&P3Data["PonOut"]==""
        &&P4Data["Out"]==""&&P4Data["PonOut"]==""){
           if (Touched) Tc+="@x";
           else Tc+="@y";
        }
        return 1;
}
int ch(string str)
{
        object me=this_player();
        mapping who;
        if (me->query("id")==P1Data["Id"]) who=P1Data;
        else if (me->query("id")==P2Data["Id"]) who=P2Data;
        else if (me->query("id")==P3Data["Id"]) who=P3Data;
        else if (me->query("id")==P4Data["Id"]) who=P4Data;
        if(!str) return 0;
        if(!wizardp(me)) return 0;
        write("�A��P"+who["Mj"]+"����"+str+" ok.\n");
        str=sort_data(str);
        who["Mj"]=str;
        return 1;
}
string query_save_file() { return __DIR__ + "past_mj1_data"; }