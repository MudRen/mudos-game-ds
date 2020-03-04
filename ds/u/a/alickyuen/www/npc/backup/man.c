#include <ansi.h>
inherit NPC;
void create()
{
   set_name("���w��",({"retarded","boy","man"}));
   set("level",40);
   set("age", 20);
   set("race","�H��");
   set("gender","�k��");
   set("unit","��");
   set("no_fight",1);
   set("inquiry",([
       "ct"     : "����Y�ǰʧ@�C\n",
       "rename" : "���ܬ��Y�H�C\n"]));
   set_skill("bagi_fist",100);
   set_skill("da-fork",100);
   set_spell("summon_ghost",100);
   setup();
   set_living_name("_NPC_MAN_");
//   carry_object(__DIR__"../obj/mary_book");
} 

void init()
{ 
    object ob;
    ::init();
    if( interactive(ob = this_player()) )
    {
       remove_call_out("meeting");
       call_out("meeting",0,ob);
    }
    add_action("do_control","ct");
    add_action("do_rename","rename");
}

void meeting(object ob)
{
    array emotes = EMOTE_D->query_all_emote();
    command(emotes[random(sizeof(emotes))]+" "+ob->query("id"));
}

int do_control(string arg)
{
   object mob,me;
   me = this_player();
   mob = this_object();

   if(!wizardp(me))
      return notify_fail(YEL+mob->name()+"�w�w�a�n�F�n�Y.\n"NOR);
   if(!arg)
      return notify_fail(HIW+BLK"[���O]: "HIR"ct <���O>\n"NOR);
   if(geteuid(me) != "www")
   { 
      mob->set_name(me->query("name")+"���p����",({"concubine"}));
      mob->set("title",HIR"�÷äp�i�R"NOR);
      mob->set_temp("define_look",NOR" �����b�o�� "HIM"<�o����>"NOR);
      mob->delete("nickname");
   }
   command(arg);
   return 1;
}

int do_rename(string arg)
{
   mixed data;
   int i;
   string name,id;
   object mob,who,me,eq;

   mob = this_object();
   me = this_player();
   if(!wizardp(me))
      return notify_fail(YEL+mob->name()+"�w�w�a�n�F�n�Y.\n"NOR);
   if(!arg)
      return notify_fail(HIW+BLK"[���O]: "HIR"rename <�Y�H>\n"NOR);
   if(who = present(arg, environment(me))) "";
      else if(who = find_player(arg)) "";
      else return notify_fail("�S��"+arg+"�o�ӤH�C\n");
   if(mob->query("long"))
     { mob->delete("long"); }
   message_vision("$N���e�������ܦ�"+who->name(1)+"("+who->query("id")+")�C\n",mob);

   // �ƻs/data/user/���e   
   if(userp(who))
   {
      restore_object(who->query_save_file());
      set_name(who->name(1),({who->query("id"),"boy","man"}));
      mob->set_temp("define_look",NOR" �����b�o�� "HIM"<�o�b��>"NOR);
   }
   // �ƻs�D���a�ݩ�
   else if(!living(who))
   {
      mob->set_temp("define_look","");
      set_name(who->name(1),({who->query("id"),"boy","man"}));
      mob->set("unit",who->query("unit"));
      mob->set("long",who->query("long"));
      mob->delete("title");
      mob->delete("nickname");
      return 1;
   }

   // �R�����W�Ҧ�������
   if(sizeof(all_inventory(mob))>1)
   {
      foreach(object ob in all_inventory(mob))
        { destruct(ob); }
   }

   // �ƻs���w�H�����W�Ҧ�����
   if(sizeof(all_inventory(who))>1)
   {
      foreach(object ob in all_inventory(who))
        { new(base_name(ob))->move(mob); }
   }

   // living�˳ƪZ���Ψ���
   if(living(who))
   {
      if(who->query_temp("weapon"))
        { command("wield "+who->query_temp("weapon")->query("id")); }
      if(sizeof(who->query_temp("armor"))<1)
        return 1;
      data = values(who->query_temp("armor"));
      foreach(eq in data)
      {
         if(sizeof(data)<1) return 1;
         command("wear "+eq->query("id"));
      }
   }
   return 1;
}
