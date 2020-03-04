//oceaner.c
#include <path.h>
#include <ansi.h>
#include <dbase.h>
#define STOREDROOM LUKY+"pearl/temp/auto"
inherit NPC;
void create()
{
set_name("�٭p",({"buddy"}));
set("level",38);
set("age",32);
set("long","�L�O�������٭p, �M���t�d�~�e�M�ɳc���(Automat)���f�C\n");
set("gender", "�k��");
set_skill("tenken",20);
map_skill("unarmed","tenken");
set("coin",300+random(100));
set("chat_chance",8);
set("chat_msg",({
  (:command,"sing":),
"�٭p���b�����a�ݵۭ�R�����e��...\n",
"�٭p�ݨ캩�e�ѤW���гJ�W�H�Ԥ����������j��.\n",
}) );
set("inquiry/automat", @LONG
  �p�G�c����S�f����, �A�i�H�s��(tell)�ɳf.
LONG );
set_temp("apply/armor",random(380));
set_temp("apply/damage",random(76));
set_temp("apply/dodge",random(76));
setup();
set_skill("unarmed",160);
}

void init()
{
add_action("do_tell","tell");
}

int do_tell(string arg)
{
 if(arg=="buddy �ɳf" || arg=="buddy supply")
 {
  command("say �A�Ѯv�S�ЧA���ܭn�[��'��'�r�����§����?"); 
  return 1;	
 }
 if(arg=="buddy �иɳf" || arg=="buddy please")
 {
  message_vision("\n$N�i�D�٭p��: �иɳf\n",this_player());
  if(this_object()->query("supply"))
  {
   command("say �е��@�U, �ګݷ|��ݧ����e�N�h��.."); 
   return 1;
  }
  this_object()->set("supply",1);
  call_out("supply1",140);
  call_out("supply2",200);
  command("say �c����S�f�F��? �n��, �ڵ��@�U�N�h�ɳf."); 
  return 1;
 }
return 0;
}

void supply1()
{
 command("go south");
 command("go west");
 command("hmm");
 command("say �е��@�U, �ڥߨ�}�l�ɳf.");
 set("long","�@�ӹD�㩱���٭p, ���b�V�O���ɳc������f�C\n");
 set("chat_chance",25);
 set("chat_msg",({
"�٭p���b�C�C���ɥR�c��������~...\n",
"�٭p�@�Ӥ��p�ߧ���ɦn���F�賣�˭ˤF�X��.. �٭p�S�}�l���ɤF..\n",
}) );
}

void supply2()
{
 object stroom, obj;
 if(!find_object(STOREDROOM)) load_object(STOREDROOM);
 stroom=find_object(STOREDROOM);
 if(obj=present("green tea",stroom))
 {
  if(obj->query("amount")<100) obj->set("amount",100);
  command("say �n�F, ���ɧ��F. �T�T!!");
  command("jump");
 } else
 {
  command("say ��.. �c����n���G�٤F...�ڨS��k..");
  command("shrug"); 
 }
 command("wave"); 
 command("go east");
 command("go north");
 this_object()->delete("supply");
 set("long","�L�O�����٭p, �M���t�d�~�e�M�ɳc������f�C\n");
 set("chat_chance",8);
 set("chat_msg",({
  (:command,"laugh":),
"�٭p���b�����a�ݵۭ�R�����e��...\n",
"�٭p�ݨ캩�e�ѤW���гJ�W�H�Ԥ����������j��.\n",
}) );

}