#include <ansi.h>
inherit "/feature/autoload.c";
inherit ITEM;
int do_set_npc(string arg);
int do_set_npc_long(string arg);
int do_set_chat_speed(string arg);
int do_add_chat(string arg);
int do_del_chat(string arg);
string Skill = "unarmed";
int do_make_npc();
int do_show_all_npc();
int Age=14,Lv = 1,ChatSpeed=10,Check = 1,Wimpy = 0;
string Name = "�h�L";
string Id = "noname";
string Attitude ="";
string Gender="�k�m";
string Race ="�H��";
string Long = "";
string NickName = "";
string Title = "";
string ChatBuffer=({}),Pursuer="";
void create()
{
     set_name(HIC"NPC"HIB"�s�y��"NOR, ({ "npc maker", "maker" }) );
     set("long","�Х� < help_npcmaker > �ݻ����C\n");
     set("unit", "��" );
     set("team_cwd","/u/e/eeman/npc/");//�s�񪺥ؿ�
}
void init()
{
        seteuid(getuid(this_player()));
        add_action("check_command","");
}
int check_command(string arg)
{
        string verb;
        mapping can_command = ([
                "make_npc"         : "�гy�@���ͪ�",
                "mn"               : 1,
                "set_npc"          : "�]�w���ݩ�,�� [help_set_npc]",
                "sn"               : 1,
                "set_npc_long"     : "�]�w�ͪ��b�Q�[�ݮɪ��ԭz",
                "snl"              : 1,
                "set_chat_speed"   : "�]�w���ܳt�׶V�p���ܶV�C",
                "scs"              : 1,
                "add_chat"         : "�W�[�@�Ӱʧ@,�Ҧpadd_chat say �ڬOxx",
                "ac"               : 1,
               "del_chat"         : "�R���@�Ӱʧ@",
                "help_npcmaker"    : 1,
                "help_set_npc"     : 1,
                "looknpc"          : "�i�H�ݧA�w�g�]�w�F����",
                "call_npc"         : "�s�X�w�������ͪ�-������-",
                "del_npc"          : "�û��M���w�������ͪ�(�N�O�s�ɤ@�_�M��)",
                "dest_npc"         : "��o�өж������ͪ��M��(dest_npc id)",
                "npclist"          : "�d�ݧA�w�g�гy�F�h�֥ͪ�",
        ]);
        if (!query("team_cwd")) return notify_fail("�o��"+ name() +"�S�����еL�;
        verb = query_verb();
        if (!can_command[verb]) return 0;
        else if (verb=="make_npc"   || verb=="mn") return do_make_npc();
        else if (verb=="set_npc"    || verb=="sn") return do_set_npc(arg);
        else if (verb=="set_npc_long" || verb=="sl") return do_set_npc_long(arg;
        else if (verb=="add_chat"   || verb=="ac") return do_add_chat(arg);
        else if (verb=="set_chat_speed"   || verb=="scs") return do_set_chat_sp;
        else if (verb=="dest_npc"){
                object ob;
                if (!arg) return 0;
                if (!ob = present(arg,environment(this_player())))
                   return notify_fail("�A�n�M���֡S\n");
                if (ob->query("player_npc")!=query("team_cwd"))
                   return notify_fail("�A����M���o�ӥͪ�.\n");
                seteuid(getuid());
                destruct(ob);
                return notify_fail("�M��ok.\n");
        }else if (verb=="looknpc"){
printf("�o�ӥ��X�ͪ��ͪ����]�w��:\n����(lv):%d.\n�W�r(name):%s.\nid:%s.\ntitle:;
                 return 1;
        }else if (verb=="help_npcmaker"){
          int i;
          string *help;
          arg ="";
          help = keys(can_command);
          for (i=0;i < sizeof(can_command);i++){
              if (intp(can_command[help[i]])) continue;
              if (help[i]=="help_set_room") continue;
              arg += sprintf("%-13s %s�C\n",help[i],can_command[help[i]]);
          }
          write(arg);
          return 1;
        }else if (verb=="help_set_npc"){
                 arg=@TEXT
�A�i�H�]�w����:
age          (�~��)
attitude        (�ݩ�  �]�� aggressive �|�۰ʧ����H)
lv              (���ť�1��100).
name            (�W�r).
id              (�^��W�r).
title           (�ٸ�).
nickname        (�κ�).
skill           (�ޯ�).
race            (�ر�  �{�b�u���H�����~���).
gender          (�ʧO  �k��,�k��,����,�۩�,��).
money none      (�o�ӥͪ��S����  �p�ʪ�..����).
pursuer YES     (�o�ӥͪ��|�l���H).
wimpy      (�o�ӥͪ���g����h�֮ɷ|�k�]).
TEXT;
                 write(arg);
                 return 1;
        }else if (verb=="npclist"){
                 return do_show_all_npc();
        }else if (verb=="del_npc"){
                 object ob;
                 if (!arg) return 0;
                 if (!ob = present(arg,environment(this_player()))){
                    if ( sscanf(arg,"%*s.c") != 1 ) arg += ".c";
                    if (file_size(query("team_cwd")+arg) < 0) return notify_fai;
                    if (!ob = load_object(query("team_cwd")+arg)) return notify;
                 }
                 if (ob->query("player_npc")!=query("team_cwd"))
                    return notify_fail("�A����R���o�ӥͪ�.\n");
                 seteuid(getuid());
                 destruct(ob);
                 rm(query("team_cwd")+arg);
                 return notify_fail("�M���ɮ�"+arg+"ok.\n");
        }else if (verb=="call_npc"){
                 object ob;
                 if (!arg) return 0;
                 if ( sscanf(arg,"%*s.c") != 1 ) arg += ".c";
                 if (file_size(query("team_cwd")+arg) < 0) return notify_fail(";
                 if (!ob = new(query("team_cwd")+arg)) return notify_fail(arg +;
                 if (ob->query("player_npc")!=query("team_cwd"))
                    return notify_fail("�A���ఽ���O�H���ͪ�.\n");
                 ob->move(environment(this_player()));
                 return 1;
        }
}
int do_make_npc()
{
        string code,file,dir;

        dir = resolve_path(query("team_cwd"), 0);
        file = sprintf(dir+"npc%d.c",sizeof(get_dir(dir, -1)));
        code = @NPC_CODE
inherit NPC;
void create()
{
NPC_CODE;
        code += sprintf("\tset(%cplayer_npc%c,%c%s%c);\n",34,34,34,query("team_;
        code += sprintf("\tset_name(%c%s%c,({%c%s%c}));\n",34,Name,34,34,Id,34);
        code += sprintf("\tset(%cage%c,%d);\n",34,34,Age);
        if (Race!="�H��") code += sprintf("\tset(%crace%c,%c%s%c);\n",34,34,34,;
        if (Wimpy!=0) code += sprintf("\tset(%cenv/wimpy%c,%d);\n",34,34,Wimpy);
        if (Long!="") code += sprintf("\tset(%clong%c,@LONG\n%s\nLONG\n\t);\n",;
        if (Attitude!="") code += sprintf("\tset(%cattitude%c,%c%s%c);\n",34,34;
        if (Pursuer!="")  code += sprintf("\tset(%cpursuer%c,1);\n",34,34);
        if (NickName!="") code += sprintf("\tset(%cnickname%c,%c%s%c);\n",34,34;
        if (Title!="") code += sprintf("\tset(%ctitle%c,%c%s%c);\n",34,34,34,Ti;
        if (sizeof(ChatBuffer)){
           int i;
           code += sprintf("\tset(%cchat_chance%c,%d);\n",34,34,ChatSpeed);
           code += sprintf("\tset(%cchat_msg%c,({\n",34,34);
        string code,file,dir;

        dir = resolve_path(query("team_cwd"), 0);
        file = sprintf(dir+"npc%d.c",sizeof(get_dir(dir, -1)));
        code = @NPC_CODE
inherit NPC;
void create()
{
NPC_CODE;
        code += sprintf("\tset(%cplayer_npc%c,%c%s%c);\n",34,34,34,query("team_;
        code += sprintf("\tset_name(%c%s%c,({%c%s%c}));\n",34,Name,34,34,Id,34);
        code += sprintf("\tset(%cage%c,%d);\n",34,34,Age);
        if (Race!="�H��") code += sprintf("\tset(%crace%c,%c%s%c);\n",34,34,34,;
        if (Wimpy!=0) code += sprintf("\tset(%cenv/wimpy%c,%d);\n",34,34,Wimpy);
        if (Long!="") code += sprintf("\tset(%clong%c,@LONG\n%s\nLONG\n\t);\n",;
        if (Attitude!="") code += sprintf("\tset(%cattitude%c,%c%s%c);\n",34,34;
        if (Pursuer!="")  code += sprintf("\tset(%cpursuer%c,1);\n",34,34);
        if (NickName!="") code += sprintf("\tset(%cnickname%c,%c%s%c);\n",34,34;
        if (Title!="") code += sprintf("\tset(%ctitle%c,%c%s%c);\n",34,34,34,Ti;
        if (sizeof(ChatBuffer)){
           int i;
           code += sprintf("\tset(%cchat_chance%c,%d);\n",34,34,ChatSpeed);
           code += sprintf("\tset(%cchat_msg%c,({\n",34,34);
           for (i=0; i < sizeof(ChatBuffer); i++){
               code += sprintf("\t    (: command,%c%s%c :),\n",34,ChatBuffer[i];
           }
           code += "\t}) );\n";
        }
        code += "\tsetup();\n";
        if (Check)
           code += sprintf("\tadd_money(\"silver\",%d);\n",Lv);
        code += "}\n";
        if (!write_file(file,code,1) ) return notify_fail("�g�J�ɮץ��ѡC\n");
message_vision(HIR"\n�h�L"HIW"���D�G�D���A���ƽЧh�J�C\n"NOR,this_player());
        "/cmds/wiz/clone.c"->main(this_player(),file);
        Lv = 1;
        Age = random(60)+14;
        Attitude = "";
  Name="�h�L";
        Id = "noname";
        Long = "";
        NickName = "";
        Title = "";
        ChatSpeed=3;
        ChatBuffer=({});
        Check = 1;
        string code,file,dir;

        dir = resolve_path(query("team_cwd"), 0);
        file = sprintf(dir+"npc%d.c",sizeof(get_dir(dir, -1)));
        code = @NPC_CODE       
        Gender="�k�m";
        Race ="�H��";
        Pursuer="";
        Wimpy=0;
        return 1;
}
int do_set_npc(string arg)
{
        mixed data;
        string prop;

        if (!arg || sscanf(arg,"%s %s",prop,data)!=2) return 0;
        if (prop=="name") Name = data;
        else if (prop=="id")   Id = data;
 else if (prop=="nickname") NickName ->trans_color(data);
        else if (prop=="title") Title = data;
        else if (prop=="lv" || prop=="level"){
                sscanf(data,"%d",data);
       }else if (prop=="skill") Skill = data;
        else if (prop=="race"){
                if (data=="���~"){
                   if (Gender=="�k��") Gender = "����";
                   Race = data;
        string code,file,dir;

        dir = resolve_path(query("team_cwd"), 0);
        file = sprintf(dir+"npc%d.c",sizeof(get_dir(dir, -1)));
        code = @NPC_CODE
        else if (prop=="gender"){
                if (data=="�k��"
                ||  data=="�k��"
                ||  data=="����"
                ||  data=="�۩�") Gender = data;
                else write("�ʧO�u�i�H�O�k��,�k��,�۩ʩζ���.\n");
        }
        else if (prop=="age") sscanf(data,"%d",Age);
        else if (prop=="attitude") Attitude = data;
        else if (prop=="money" && data=="none") Check=0;
        else if (prop=="pursuer" && data =="YES") Pursuer = "YES";
        else if (prop=="wimpy") sscanf(data,"%d",Wimpy);
        write("ok.\n");
        return 1;
}
int do_set_npc_long(string arg)
{
        if (!arg) return 0;
        Long = arg;
        return 1;
}
        string code,file,dir;

        dir = resolve_path(query("team_cwd"), 0);
        file = sprintf(dir+"npc%d.c",sizeof(get_dir(dir, -1)));
        code = @NPC_CODE

int do_set_npc_long(string arg)
{
        if (!arg) return 0;
        Long = arg;
        return 1;
}
int do_add_chat(string arg)
{
        if (!arg) return 0;
        ChatBuffer+=({arg});
        printf("�z�W�[[%s]�o�Ӱʰ�.\n",arg);
        return 1;
}
int do_del_chat(string arg)
{
        if (!arg) return 0;
        ChatBuffer-=({arg});
        printf("�z�R���ʰ����e����[%s].\n",arg);
        return 1;
}
int do_set_chat_speed(string arg)
{
        int i;
        if (!arg) return 0;
        if (sscanf(arg,"%d",ChatSpeed)!=1) return 0;

        printf("�z�]�w���ܪ��t�׬�[%d].\n",ChatSpeed);
        return 1;
}
int do_show_all_npc()
{
        int i;
        mixed *files;
        string str="",dir,temp,err;
        object ob;

        dir = resolve_path(query("team_cwd"), 0);
        files = get_dir(dir, -1);
        if (!sizeof(files)) return notify_fail("�S���o�ӥؿ��C\n");
        for (i=0; i <sizeof(files); i++){
            if (file_size(dir + files[i][0]) < 1) continue;
            if (files[i][0][<2..]!=".c") continue;
            if (!ob = find_object(dir + files[i][0])) err = catch(call_other(di;
            if (stringp(dir + files[i][0])) err = catch(ob = load_object(dir + ;
            if (err) continue;
            temp = "�ͪ��ɦW�R" + files[i][0];
            str += sprintf("%s - [%s]\n", temp, ob->short());
        }
        this_player()->start_more(str);
        return 1;
}
{
#include <ansi.h>
inherit "/feature/autoload.c";
inherit ITEM;
int do_set_npc(string arg);
int do_set_npc_long(string arg);
int do_set_chat_speed(string arg);
int do_add_chat(string arg);
int do_del_chat(string arg);
string Skill = "unarmed";
int do_make_npc();
int do_show_all_npc();
int Age=14,Lv = 1,ChatSpeed=10,Check = 1,Wimpy = 0;
string Name = "�h�L";
string Id = "noname";
string Attitude ="";
string Gender="�k�m";
string Race ="�H��";
string Long = "";
string NickName = "";
string Title = "";
string *ChatBuffer=({}),Pursuer="";
void create()
{

     set_name(HIC"NPC"HIB"�s�y��"NOR, ({ "npc maker", "maker" }) );
     set("long","�Х� < help_npcmaker > �ݻ����C\n");
     set("unit", "��" );
     set("team_cwd","/u/m/morral/npc/");//�s�񪺥ؿ�
}
void init()
{
        seteuid(getuid(this_player()));
        add_action("check_command","");
}
int check_command(string arg)
{
        string verb;
        mapping can_command = ([
                "make_npc"         : "�гy�@���ͪ�",
                "mn"               : 1,
                "set_npc"          : "�]�w���ݩ�,�� [help_set_npc]",
                "sn"               : 1,
                "set_npc_long"     : "�]�w�ͪ��b�Q�[�ݮɪ��ԭz",
                "snl"              : 1,
                "set_chat_speed"   : "�]�w���ܳt�׶V�p���ܶV�C",
                "scs"              : 1,
                "add_chat"         : "�W�[�@�Ӱʰ�,�Ҧpadd_chat say �ڬOxx",
#include <ansi.h>
inherit "/feature/autoload.c";
inherit ITEM;
int do_set_npc(string arg);
int do_set_npc_long(string arg);
int do_set_chat_speed(string arg);
int do_add_chat(string arg);
int do_del_chat(string arg);
string Skill = "unarmed";
int do_make_npc();
int do_show_all_npc();
int Age=14,Lv = 1,ChatSpeed=10,Check = 1,Wimpy = 0;
string Name = "�Y�ͪ�";
string Id = "mob";
string Attitude ="";
string Gender="�k��";
string Race ="�H��";
string Long = "";
string NickName = "";
string Title = "";
string *ChatBuffer=({}),Pursuer="";
void create()
