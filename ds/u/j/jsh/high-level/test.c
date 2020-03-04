#include <ansi.h>
inherit NPC;  
mapping *combat_action = ({
        ([      "action":       "$N�V�W�@���A�@�C��$n��$l�w�F�U�h�I",
                "attact_type":  "bar",  // �]�w�ޯ઺��������
                                        // ������ �ͪ�(bio) �~��(bar)
                                        // �]�k(wit)���F(sou)���(tec)
                "damage_type":  "�C��",
        ]), 
        ([      "action":       "$N�j�ھ�B�A�H�αN�⤤���C�A��$n��$l���F�@�ӤQ�r",
                "attact_type":  "tec",
                "damage_type":  "����",  
        ]),
        ([      "action":       "$N�����H��y�P��$n���ۦ��A$n���ƳQ�ݯ}�A�Q$N������W�@�C",
                "attact_type":  "bio",
                "damage_type":  "���",
        ]),
});  
void heal(); 
//void let_delay();
void create()
{
        set_name(HIC"�ȥ~�ѤH"NOR,({"master shang-wai old-man","man","master","old","shang","wai"}));
        set("long" ,@LONG  
�e�����Щl�H�a�կP�������A�b�Z�ǹҬɤW�A��a�կP�󰪤@�h
�A�u�O�ȥ~�ѤH�߷R�M�������ҡA�b��ͪ��Ŷ��A�|�Q�Q�C�k��
�ۦ��A�p�����W�ХX�e�����ҵL�k�m�N���C�k�A�p�G�A�Q���L��
�v�A��..�Q�Q��k�a�A�����w�L�|���A�C 
[PS:�ȥ~�ѤH���w�ᦳ����C���F��A�A�i�H�򥦲��(cchat)�A�����w�|���Ǧ�ì�C]
LONG
);
        set("nickname", HIC"�ѯe��"NOR );
        set("attitude", "friendly"); 
        set("age", 90); 
        set("no_fight",1);
        set("gender","�k��");
        set("combat_exp", 450000);
        set("level", 60);
        set("title",HIR"��  ��"NOR);
        set("max_ap",20000); 
        set("max_hp",10000);//�ѤH..hp�֤@�I
        set("max_mp",20000);
        set("class1","�e����"); 
        set("class2","�ѯe��"); 
        set("flurrydodge",1);
        set_temp("apply/armor",200);
        set_skill("fogseven",100);
        set_temp("sorgitimes",20);
        set_skill("unarmed", 100);
        set_skill("sword",100);
        set_skill("moon_force",100);
        set_skill("dodge", 100);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("sorgi_sword",100); 
        set_skill("sevenstar-sword",100); 
        set_skill("star-sword",100);
        set_skill("sorsin-force",100);     
        map_skill("sword","star-sword");
        map_skill("dodge","fogseven");
        set("guild_gifts",({ 3,5,5,7}));   //�`�X=20
//      �u�|�ɮv�i�H�бª��ޯ�C��
        set("guild_skills",([
  "sorsin-force" : ({ 175,5,100 }), 
]));

        set("no_check_class",1);
        set("adv_class",2);
        set("chat_chance",8);
        set_temp("class_wind/power",400);
        set("chat_msg", ({
  "�ѯe�������R�ۤ⤤���C�A�C�C���L�A�C��֡A�X�ۺC�C\n",  
  (:command("smile"):), 
  (:command("sigh"):),
  (:command("hmm"):), 
  (:heal:),  
  (:command("exert moon_force recover"):), 
  (:command("exert moon_force recover"):),
}));
        set("chat_chance_combat",33);
        set("chat_msg_combat",({
  (:command,"exert star-sword tian":),
  (:command,"exert star-sowrd nine":),
  (:command,"exert star-sword penuma-sword":),
  (:command,"exert sorsin-force":),
  (:command("exert moon_force moon-arc"):), 
  //(:let_delay:),
}));
        set("default_actions", (: call_other, __FILE__, "query_action" :));
        setup();
        carry_object("/u/j/jangshow/sword")->wield();
       // carry_object(__DIR__"eq/sandal")->wear();
} 
mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];  
} 
void init()
{
        add_action("do_skill_list","list");
        add_action("do_skill_train","train");      
        add_action("do_cchat","cchat");
        add_action("do_no","no");
        add_action("do_yes","yes");   
        add_action("do_thief","thief");
        add_action("do_nod","nod");
        add_action("do_give","give");
        if(!query("no_join") || query("no_join")!=1)
        add_action("do_guild_join","join");
        add_action("do_for","for");}
int do_skill_list(string arg)
{
        GUILDMASTER->do_skill_list(this_object(),this_player(),arg);
        this_player()->set("no_check_class",1); // �קK�C�X�ˬd¾�~���T��
        write("\n");
        return 1;
}
int do_skill_train(string arg)
{
        object ob, me;

        ob = this_object();
        me = this_player();

        GUILDMASTER->do_skill_train(ob,me,arg);
        return 1;
}   
int do_thief(string arg)
{
    object me,ob;
    me=this_player();
    ob=this_object();
    if(!arg||arg!="thief")
      return notify_fail("����?\n");
    if(!me->query("class1")=="�s��u�|") return 0;
    {
    message_vision("�ȥ~�ѤH���G���A�O�s��H\n",me);
    me->add_temp("tf",1);
    }
    return 1;
}
int do_nod(string arg)
{
    object me,ob;
    me=this_player();
    ob=this_object();
    if(!me->query_temp("tf")==1) return 0;
    if(arg!="master") return notify_fail("nod master�Y�i.\n");
    message_vision("$N��ȥ~�ѤH�I�F�I�Y�C\n",me);
    {
    message_vision("�ȥ~�ѤH��$N���F�@�Ǯ�����..\n",me);
    tell_object("�A�h���ڧ˭ӪF��n��..?�h���ڷd�@�M�F���..�n��浹�ڴN�i�H�F...�ڷ|���A���઺�C\n",me);
    me->delete_temp("tf");
    me->add_temp("soul_armpr",1);
    }
    return 1;
}
int do_give(string arg)
{
    object obj,me=this_player(),ob=this_object();
    if(!me->query_temp("soul_armor")==1) return 0;
    if(arg !="soul armor")return notify_fail("�A�n������?\n");
      {
      message_vision("$N���ȥ~�ѤH�@���F���\n",me);
      ob->command(:wear armor:);
      obj=new(__DIR__"obj/perple-dagger");
      obj->move(ob);
      //ob->command(:give dagger to "+me->
      me->delete_temp("soul_armor");
      }
      return 1;
}
int do_cchat(string arg)
{
    object me,ob;
    me=this_player();
    ob=this_object();
    if(!arg ||arg!="�C") 
      return notify_fail("�A�n�ᤰ��?\n");
      {
      message_vision("$N���D�G�C�I\n"
                     "�ȥ~�ѤH���D�G�������ӧA�]���w�C�ڡI\n"
                     "[yes or no,no���Х��W�A������(�� ���k,�k�N,�@�k)]\n",me);
      ob->set_temp("yess",1); 
      ob->set_temp("noo",1);
      } 
    return 1;
} 
int do_yes(string arg)
{
    object me,ob;
    me=this_player();
    ob=this_object();
    if(!ob->query_temp("yess")==1) return 0;
    {
    message_vision("$N�I�I�Y�����G�O���I\n"
                   "�ȥ~�ѤH���������G���r�r�㨺�A��ڪ�����O�@�˪�...��������..������..\n"
                   "�ȥ~�ѤH���G�u�O..�ѤҦ��ͪ����@�A�N�O�Q�����Q��ڭn���C\n"
                   "�ȥ~�ѤH���G��..�ڦ~���w�L�b�ʦ��l�A�u�Ȥߦ��l�O�����r..�����D�֯����کO[for]�H\n",me);
    } 
    ob->delete_temp("yess",1);
    ob->delete_temp("noo",1);
    me->add_temp("fortp",1);
    return 1;
} 
int do_no(string arg)
{
    object me,ob;
    me=this_player();
    ob=this_object();
    if(!ob->query_temp("noo")==1) return 0;   
    if(arg!="���k" || arg!="�k�N" || arg!="�@�k") return 0;   
    {
    if(arg=="���k"){
       me->add_temp("�K����",1);}
    else{
        if(arg=="�k�N"){
        me->add_temp("���Z��",1);}
        else {
             if(arg=="�@�k"){
             me->add_temp("������",1);} 
             }  
        } 
    }
    message_vision("$N���G�ڪ�����O"+arg+"�I\n"
                   "�ȥ~�ѤH���G��ӧA������O"+arg+"�r..\n"
                   "�ȥ~�ѤH���G��..�Q���Q�񹺤�..�i�O�ۭt�ѤH�a�r..������..\n" 
                   "�ȥ~�ѤH���G��..�ڴN�����..�u���@�����|��..��������..\n",me);  
    {
    ob->kill_object(environment(this_player()));  
    ob->delete_temp("yess",1);
    ob->delete_temp("noo",1);   
    }
    return 1;
} 
void is_fighting()
{
     object me,ob;
     me=this_player();
     ob=this_object();
     if(ob->is_fighting() )
       return notify_fail("�t���ˬd��...\n"); 
     {
       if(me->query_temp("�K����") != me->query("class1")=="�K����")  
       {
       else if(me->query_temp("���Z��") != me->query("class1")=="���Z��")
            { 
            else if(me->query_temp("������") != me->query("class1")=="������")
            } 
        }
     message_vision("�ȥ~�ѤH���G��$N���ۦ��A$N��軡�����O�F�ڪ�...��..�N���ѤҤ��^���F..\n"
                    "�ȥ~�ѤH�V�W�Ť@���A���������H�v..\n",me);
     destruct(ob); 
     }
     else{
     message_vision("�ȥ~�ѤH�������F�X�n�G��������.....\n",me);
     }
}
int do_for(string arg)
{
        object me; 
        me=this_player(); 
        object obj; 
        if(!me->query_temp("fortp")==1) return 0;
        if(arg=="") return notify_fail("�A�n������[�C,�Х����W]?\n"); 
        {
        if(arg=="wooden sword")
        {
        if(!obj=present("wooden sword",me))
        {
        return notify_fail("�ȥ~�ѤH���F�_�ӡA�J�ӵ����@�F�@.....�ĤF�f��A�n�F�n�Y�C\n");
        }
        if(this_object()->query_temp("wooden")==1)
                {
                tell_object("�A���L�ȥ~�ѤH�F�C\n",me);
                return 1;
                }
                destruct(obj);
                message_vision("�ȥ~�ѤH�����@�G�A���D�G��C�C�����A�A�_�ӧ������O�O��A�n..�n�n..\n"                               "�ȥ~�ѤH��F��$N���Y�C\n",me);
                set_temp("wooden",1);
                return 1;
        }
///////////////////////////////////////////////////////////////////////// �j�_�Ӥ���n��...��ڦӨ�
        if(arg=="long sword" && arg=="longsword" ) //DS�̪����C����ؼg�k.
        { 
      //if(!obj=present({"long sword","longsword"},me)); 
        if(!obj=present("long sword",me))   
        if(!obj=present("longsword",me)) 
        {
        return notify_fail("�ȥ~�ѤH���F�_�ӡA�J�ӵ����@�F�@.....�ĤF�f��A�n�F�n�Y�C\n");
        }
        if(this_object()->query_temp("long")==1)      
        {
                tell_object("�A���L�ȥ~�ѤH�F�C\n",me);
                return 1;
                }
                destruct(obj);
                message_vision("�ȥ~�ѤH�����@�G�A���D�G���C�D�Z�L�H�h���򥻰t���A�b�Z�L���a��A�ѤҲ`�P�֩w..\n"
                               "�ȥ~�ѤH�u��v���@�n"\n"
                               "�ȥ~�ѤH��F��$N���Y�C\n",me);
                set_temp("long",1); //��ت��C��temp����long
                return 1;
        }
///////////////////////////////////////////////////////////////////////////////
        if(arg=="sevenstar barb sword")
        {       
        if(!obj=present("sevenstar barb sword",me))
        {
        return notify_fail("�ȥ~�ѤH���F�_�ӡA�J�ӵ����@�F�@.....�ĤF�f��A�n�F�n�Y�C\n");
        }
        if(this_object()->query_temp("seven")==1)
                {
                tell_object("�A���L�ȥ~�ѤH�F�C\n",me);
                return 1;
                }
                destruct(obj);
                message_vision("�ȥ~�ѤH�����@�G�A���D�G���r�r��A���կP���C�����ڮ��Ӱ�...\n"
                               "�ȥ~�ѤH�u��v���@�n...�n�a..�N��O��L�ɪ��a...������\n"
                               "�ȥ~�ѤH��F��$N���Y�C\n",me);
                set_temp("seven",1);
                return 1;
        }
///////////////////////////////////////////////////////////////////////////////////
        if(arg=="shang-ing sword")
        {
        if(!obj=present("shang-ing sword",me))
        {
        return notify_fail("�ȥ~�ѤH���F�_�ӡA�J�ӵ����@�F�@.....�ĤF�f��A�n�F�n�Y�C\n");
        }
        if(this_object()->query_temp("shang")==1)
                {
                tell_object("�A���L�ȥ~�ѤH�F�C\n",me);
                return 1;
                }
                destruct(obj);
                message_vision("�ȥ~�ѤH�����@�G�A���D�G�z...�o��C���C��u�l�ާ�..@.@\n"
                               "�ȥ~�ѤH���G�u�O�U�ݷU���w....�n..�n�n..\n"
                               "�ȥ~�ѤH��F��$N���Y�C\n",me);
                set_temp("shang",1);
                return 1;
        }  
//////////////////////////////////////////////////////////////////////////////////////       
        if(arg=="god sword")
        {
        if(!obj=present("god sword",me))
        {
        return notify_fail("�ȥ~�ѤH���F�_�ӡA�J�ӵ����@�F�@.....�ĤF�f��A�n�F�n�Y�C\n");
        }
        if(this_object()->query_temp("god")==1)
                {
                tell_object("�A���L�ȥ~�ѤH�F�C\n",me);
                return 1;
                }
                destruct(obj);
                message_vision("���Z�C�}�l�o�X��䪺�n��...���G�ܻ{�P�{�b��������H..\n"                               "�ȥ~�ѤH�����@�G�A���D�G����u�O���⪺�@��C�A�n���F��..\n"
                               "�ȥ~�ѤH���G�n..�n�n..\n"
                               "�ȥ~�ѤH��F��$N���Y�C\n",me);
                set_temp("god",1);
                return 1;
        } 
/////////////////////////////////////////////////////////////////////////////////////////        
        if(arg=="old sword")
        {
        if(!obj=present(old sword",me))
        {
        return notify_fail("�ȥ~�ѤH���F�_�ӡA�J�ӵ����@�F�@.....�ĤF�f��A�n�F�n�Y�C\n");
        }
        if(this_object()->query_temp("old")==1)
                {
                tell_object("�A���L�ȥ~�ѤH�F�C\n",me);
                return 1;
                }
                destruct(obj);
                message_vision("�ȥ~�ѤH�����@�G�A���D�G�x...�o��...���إj�ª��Pı..���ӬO�j��..���_�Ӥ]�Z���⪺..\n"
                               "�ȥ~�ѤH���_�i�j�C�j�A�F���...�涳�y�����ۦ��A��$N�ݪ������f�b..�w�f�w||..\n"
                               "�ȥ~�ѤH��F��$N���Y�C\n",me);
                set_temp("old",1);
                return 1;
        } 
/////////////////////////////////////////////////////////////////////////////////////// 
        if(arg=="girl sword")
        {
        if(!obj=present("girl sword",me))
        {
        return notify_fail("�ȥ~�ѤH���F�_�ӡA�J�ӵ����@�F�@.....�ĤF�f��A�n�F�n�Y�C\n");
        }
        if(this_object()->query_temp("girl")==1)
                {
                tell_object("�A���L�ȥ~�ѤH�F�C\n",me);
                return 1;
                }
                destruct(obj);
                message_vision("�ȥ~�ѤH�����@�G�A���D�G�@�ݴN���D�O�k�ʩҥΪ��C...�u��v...\n"
                               "�ȥ~�ѤH���G���M���O�ܳ��w�A��..�o���ڷQ��ڪ��t�@�b....��..\n"
                               "�ȥ~�ѤH��F��$N���Y�C\n",me);
                set_temp("girl",1);
                return 1;
        } 
//////////////////////////////////////////////////////////////////////////////////////////////     
    if(arg=="xian-tia sword")
        {
        if(!obj=present("xian-tia sword",me))
        {
        return notify_fail("�ȥ~�ѤH���F�_�ӡA�J�ӵ����@�F�@.....�ĤF�f��A�n�F�n�Y�C\n");
        }
        if(this_object()->query_temp("tia")==1)
                {
                tell_object("�A���L�ȥ~�ѤH�F�C\n",me);
                return 1;
                }
                destruct(obj);
                message_vision("�ȥ~�ѤH�����@�G�A���D�G���r��n�����@��C�A�ӥB�]���L�S��A$N�O��ڶ}�������H\n"
                               "$N���D�G���K���C�A�j�u�����A�����O�A�R�C���ޥ��C\n"                               "�ȥ~�ѤH���G�����n...�A���F�ں��N������...\n"
                               "�ȥ~�ѤH�������A��F��$N���Y�C\n",me);
                set_temp("tia",1);
                return 1;
        } 
/////////////////////////////////////////////////////////////////////////////////////////////  
        if(arg=="se-ri sword")
        {
        if(!obj=present("se-ri sword",me))
        {
        return notify_fail("�ȥ~�ѤH���F�_�ӡA�J�ӵ����@�F�@.....�ĤF�f��A�n�F�n�Y�C\n");
        }
        if(this_object()->query_temp("se")==1)
                {
                tell_object("�A���L�ȥ~�ѤH�F�C\n",me);
                return 1;
                }
                destruct(obj);
                message_vision("�ȥ~�ѤH�����@�G�A���D�G�o��C�����A�A�N���즰������A���D�I�o�O..�I\n" 
                               "$N���D�G�S��...�o���O ���C �C\n"                               "�ȥ~�ѤH���G�S�Q��..�ѤҦ���..����ݨ�o��C..�����F..�����F..\n"
                               "�ȥ~�ѤH�������A��F��$N���Y�C\n",me);
                set_temp("se",1);
                return 1;
        } 
////////////////////////////////////////////////////////////////////////////////////      
        if(arg=="peach sword")
        {
        if(!obj=present("peach sword",me))
        {
        return notify_fail("�ȥ~�ѤH���F�_�ӡA�J�ӵ����@�F�@.....�ĤF�f��A�n�F�n�Y�C\n");
        }
        if(this_object()->query_temp("peach")==1)
                {
                tell_object("�A���L�ȥ~�ѤH�F�C\n",me);
                return 1;
                }
                destruct(obj);
                message_vision("�ȥ~�ѤH�����@�G�A���D�G���r�r��o�O����C�C...���n�����ר�...\n"
                               "�ȥ~�ѤH�������F�X�n�G������...\n"
                               "�ȥ~�ѤH��F��$N���Y�C\n",me);
                set_temp("peach",1);
                return 1; 
        }
        }
}

int do_guild_join(string str)
{  
        object me;
        me=this_player();
        if(me->query("level") < 50)
             return notify_fail("�A�������٤����C\n");   
        if(me->query_dex() < 50)
             return notify_fail("�A���ӱ�����[50]�C\n");
        if(!me->query("class1")=="�e����")
             return notify_fail("�A���O�e�������C\n");  
        if(me->query("exp") < 10000000)
             return notify_fail("�A���g��Ȥ���[1000 �U]�C\n"); 
        if(me->query("popularity") < 1000) 
             return notify_fail("�A���n�椣��[1000 �I]�C\n");
        if(me->query("class2") == "�ѯe��") return 0;
        if(!str=="�ѯe��") return notify_fail("�A�i�H�[�J �ѯe�� �C\n")
        {
        message_vision("$N�V�ȥ~�ѤH�j�ۤF�@�n�G�v�šI\n"
                       "�ȥ~�ѤH��F��$N���Y���D�G�n�n.....������....\n",me);
        if(this_object()->query_temp("wooden")==1 && this_object()->query_temp("long")==1 && 
           this_object()->query_temp("seven")==1 &&this_object()->query_temp("old")==1&&
           this_object()->query_temp("peach")==1&&this_object()->query_temp("shang")==1&&
           this_object()->query_temp("girl")==1&& this_object()->query_temp("god")==1&&
           this_object()->query_temp("se")==1&&this_object()->query_temp("tia")==1
          {
          message_vision(
          HIW"\n\t$N��b"+HIG"�i�ѯe���j�ȥ~�ѤH"+HIW"�����U�A�ǲߪZ���C\n\n"NOR,me); 
          me->set("class2","�ѯe��"); 
          me->receive_damage("exp",10000000);
          me->receive_damage("popularity",2000); 
          delete_temp("wooden);
          delete_temp("long");
          delete_temp("seven");
          delete_temp("god"); 
          delete_temp("shang"); 
          delete_temp("tia");
          delete_temp("se");
          delete_temp("old");
          delete_temp("girl");
          delete_temp("peach");
          return 1;
          }
        else
          {
          message_vision(
          "�ȥ~�ѤH���D�G$N�٨S���ڤQ��C����������������\n",me); 
         }
        return 1;
        }
} 
void heal()
{ 
     object me=this_player();
     if(query("hp") > query("max_hp")) return; 
     {
     message_vision("�ȥ~�ѤH�B�_���\�A���W���ˤf�A���G����n�F�C\n",me);
     add("hp",400); 
     }
     return;
}   
/*
void let_delay()
{
     object me=this_player(),ob=this_object();
*/
varargs int receive_damage(int damage)  //����O�ѷӧd��
{
        object me,ob;  
        me=this_player();
        ob=this_object(); 
       // int damage,c;  
       // c=me->query_armor();
        if(ob->is_fighting())  
        if(ob->query("hp")<5000)
        {
          if(random(60)<20)
          { 
         //damage=damage-c;
          damage/=2;
          message_vision(HIW"�ȥ~�ѤH�j�ܤ@�n�A�N�⤤���C�Ƭ��@�ʹs�K�D�C��A�N$N�������A����F�j�b�I\n"NOR,me,ob);
          else if(random(60)<20){ 
          damage/=2;
          message_vision(HIW"�ȥ~�ѤH�j�ܤ@�n�A�N�⤤���C�Ƭ��@�ʹs�K�D�C��A�N$N�������A�ɼƪ��ϼu�^�h�I\n"
                         +HIR"$N�������ΡA�Q�ۤv���ۦ������I\n"+NOR,me,ob);
          me->receive_damage("hp",200);}
          }
          return damage; 
        }
}
void die()
{
   object ob,obj;
   obj=new(__DIR__"/obj/money/coin");
        if( !ob = query_temp("last_damage_from") ) ob = this_player(1); 
        if( !ob ) 
        {
                ::die();
                return;
        }
        message("world:world1:vision",
   HIG"\n\n ���e�����T��"+HIC"�i�ѯe�����ȥ~�ѤH�j"+HIW"�Q"+HIR"�i"+ob->name()+"�������F�j\n\n"+NOR,users());
        
        if(random(60)<20)
          ob->add("popularity",6);
        else if(random(60)<20)
          ob->add("popularity",7);
        else if(random(60)<20)
          ob->add("popularity",8);
        ob->set("guild_rank",HIC"�ѳz"HIY"�Ѧt��z"HIC"�U��"NOR);
        ::die();
        return;
}











