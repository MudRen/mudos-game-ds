#include <ansi.h>
inherit NPC;

void create()
{
  set_name("�ƫe�D��", ({ "Bizen gou","gou"}));
  set("long",@long
�@�Ө������Ӫ��~���M�K�A���W����A�]�����ɶ����ҰʦӥR������
���Τ쬴���A�ڻ��L�����N�������O���W���M�K�Aű�y�F���֦W�M�A
���O�Ǩ�L�o�@�N�o�S������ǥX���W�@�A���L�L���W�M�������P
Ų��o�ܷP����C
long);      
  set("gender", "�k��" );
  set("age",32);
  set("level",20);
  set("race","human");
  set("no_fight",1);
  set("talk_reply","�w����{�A�D�`��p�A�n�R�Z�����ܥثe�S�f�o�A\n"
                  +"���̪��K���Q�ڮ��h�s�@�@�ǹs�ե�F�C\n");
  set("chat_chance", 15);
  set("chat_msg", ({
      "�ƫe�D���ۤ@���K�����D�G�s�󳣥��y�n�F�A�i�O�]�p�ϫo�����F\n"
     +"                          �A�˸������D�D\n",
      "�ƫe�D�軡�D�G�K�����Χ��F�A�o�A��䳣�R�ǡA�n���y�Z�����ѧ�\n"
     +"              �����áC\n",
      "�ƫe�D�觤�b��e�o�ۧb�A�����D�b�Q����H\n",
      (: command("idle") :),
     }));
  set("inquiry/�_�Ҥ�ű��","���O�@�Ǩ��㪺�]�p�ϡA�e�}�l�s���ŧ�ɡA�����D\n"
                      +"�Q�֧⤺�e�������F�A�`�o�ڨ��W���y���ե�S��k���Q�զX�����~�C\n");
  set("inquiry/�W�MŲ","���O�ڦh��j����Ʃҽs���A�̭��O�����i���O�u�@\n"
                      +"���W�M�r�C\n");
  setup();
  add_money("coin",100+random(100));
}

int accept_object(object who,object ob)
{
  object obj;
  obj=this_object();

  if(ob->query("id") == "armor design page")
  {
    if(obj->is_busy() || obj->is_fighting())
    {
      command("whisper "+who->query("id")+" �ڥ��b���A�ЧA���@�U�C\n");
      return 0;
    }
    message_vision("$N�����ƫe�D��@�i "+ob->query("name")+"�C\n",who);
    command("jump");
    obj->start_busy(10);
    obj->set_temp("givearmor",1);
    destruct(ob);
    call_out("givearmor",1,obj);
    return 1;
  }

  if(ob->query("id") == "hands design page")
  {
    if(obj->is_busy() || obj->is_fighting())
    {
      command("whisper "+who->query("id")+" �ڥ��b���A�ЧA���@�U�C\n");
      return 0;
    }
    message_vision("$N�����ƫe�D��@�i "+ob->query("name")+"�C\n",who);
    command("spank");
    obj->start_busy(10);
    obj->set_temp("givehands",1);
    destruct(ob);
    call_out("givehands",1,obj);
    return 1;
  }

  if(ob->query("id") == "boots design page")
  {
    if(obj->is_busy() || obj->is_fighting())
    {
      command("whisper "+who->query("id")+" �ڥ��b���A�ЧA���@�U�C\n");
      return 0;
    }
    message_vision("$N�����ƫe�D��@�i "+ob->query("name")+"�C\n",who);
    command("jump");
    obj->start_busy(10);
    obj->set_temp("giveboots",1);
    destruct(ob);
    call_out("giveboots",1,obj);
    return 1;
  }

  if(ob->query("id") == "neck design page")
  {
    if(obj->is_busy() || obj->is_fighting())
    {
      command("whisper "+who->query("id")+" �ڥ��b���A�ЧA���@�U�C\n");
      return 0;
    }
    message_vision("$N�����ƫe�D��@�i "+ob->query("name")+"�C\n",who);
    command("jump");
    obj->start_busy(10);
    obj->set_temp("giveneck",1);
    destruct(ob);
    call_out("giveneck",1,obj);
    return 1;
  }

  if(ob->query("id") == "surcoat design page")
  {
    if(obj->is_busy() || obj->is_fighting())
    {
      command("whisper "+who->query("id")+" �ڥ��b���A�ЧA���@�U�C\n");
      return 0;
    }
    message_vision("$N�����ƫe�D��@�i "+ob->query("name")+"�C\n",who);
    command("jump");
    obj->start_busy(10);
    obj->set_temp("givesurcoat",1);
    destruct(ob);
    call_out("givesurcoat",1,obj);
    return 1;
  }

  if(ob->query("id") == "wrists design page")
  {
    if(obj->is_busy() || obj->is_fighting())
    {
      command("whisper "+who->query("id")+" �ڥ��b���A�ЧA���@�U�C\n");
      return 0;
    }
    message_vision("$N�����ƫe�D��@�i "+ob->query("name")+"�C\n",who);
    command("jump");
    obj->start_busy(10);
    obj->set_temp("givewrists",1);
    destruct(ob);
    call_out("givewrists",1,obj);
    return 1;
  }

}

void givearmor()
{
  int i;
  object me,obj,armor;
  me=this_player();
  obj=this_object();
  i=obj->query_temp("givearmor");
  if( !me || environment(me) != environment(obj) )
  {
    command("say �x�H" + RANK_D->query_respect(me) + "�H�O�H�H");
    return;
  }
  switch( i )
  {
    case 1:
         say(CYN"�ƫe�D�讳�_�ȱi�A�����a���D�G�n���F�I�y���@�U��C\n"NOR);
         obj->set_temp("givearmor",i+1);
         call_out("givearmor",2,me);
         break;
    case 2:
         say(CYN"�ƫe�D�讳�_�@��s��A�}�l�ոˡD�D�D�C\n"NOR);
         obj->set_temp("givearmor",i+1);
         call_out("givearmor",3,me);
         break;
    case 3:
         say(CYN"�ƫe�D�軡�D�G�I��n�F�A�A���h�ոթʯ�a�C\n"NOR);
         armor=new_ob(__DIR__"eq/illusive-mirror-corslet");
         armor->move(obj);
         command("give corslet to "+ me->query("id") );
         obj->delete_temp("givearmor");
         break;
  }
}

void givehands()
{
  int i;
  object me,obj,hands;
  me=this_player();
  obj=this_object();
  i=obj->query_temp("givehands");
  if( !me || environment(me) != environment(obj) )
  {
    command("say �x�H" + RANK_D->query_respect(me) + "�H�O�H�H");
    return;
  }
  switch( i )
  {
    case 1:
         say(CYN"�ƫe�D�讳�_�ȱi�A�����a���D�G�n���F�I�y���@�U��C\n"NOR);
         obj->set_temp("givehands",i+1);
         call_out("givehands",2,me);
         break;
    case 2:
         say(CYN"�ƫe�D�觤�b��e�A�}�l�ո˹s��D�D�D�C\n"NOR);
         obj->set_temp("givehands",i+1);
         call_out("givehands",3,me);
         break;
    case 3:
         say(CYN"�ƫe�D�軡�D�G��㤣���A�A���h�ոթʯ�a�C\n"NOR);
         hands=new_ob(__DIR__"eq/ya-sha-hands");
         hands->move(obj);
         command("give hands to "+ me->query("id") );
         obj->delete_temp("givehands");
         break;
  }
}

void giveboots()
{
  int i;
  object me,obj,boots;
  me=this_player();
  obj=this_object();
  i=obj->query_temp("giveboots");
  if( !me || environment(me) != environment(obj) )
  {
    command("say �x�H" + RANK_D->query_respect(me) + "�H�O�H�H");
    return;
  }
  switch( i )
  {
    case 1:
         say(CYN"�ƫe�D�讳�_�ȱi�A�����a���D�G�n���F�I�y���@�U��C\n"NOR);
         obj->set_temp("giveboots",i+1);
         call_out("giveboots",2,me);
         break;
    case 2:
         say(CYN"�ƫe�D�觤�b��e�A�}�l�ո˹s��D�D�D�C\n"NOR);
         obj->set_temp("giveboots",i+1);
         call_out("giveboots",3,me);
         break;
    case 3:
         say(CYN"�ƫe�D�軡�D�G��㤣���A�A���h�ոթʯ�a�C\n"NOR);
         boots=new_ob(__DIR__"eq/mu-in-boots");
         boots->move(obj);
         command("give boots to "+ me->query("id") );
         obj->delete_temp("giveboots");
         break;
  }
}

void giveneck()
{
  int i;
  object me,obj,neck;
  me=this_player();
  obj=this_object();
  i=obj->query_temp("giveneck");
  if( !me || environment(me) != environment(obj) )
  {
    command("say �x�H" + RANK_D->query_respect(me) + "�H�O�H�H");
    return;
  }
  switch( i )
  {
    case 1:
         say(CYN"�ƫe�D�讳�_�ȱi�A�����a���D�G�n���F�I�y���@�U��C\n"NOR);
         obj->set_temp("giveneck",i+1);
         call_out("giveneck",2,me);
         break;
    case 2:
         say(CYN"�ƫe�D�觤�b��e�A�}�l�ո˹s��D�D�D�C\n"NOR);
         obj->set_temp("giveneck",i+1);
         call_out("giveneck",3,me);
         break;
    case 3:
         say(CYN"�ƫe�D�軡�D�G��㤣���A�A���h�ոթʯ�a�C\n"NOR);
         neck=new_ob(__DIR__"eq/iron-cloth-neck");
         neck->move(obj);
         command("give neck to "+ me->query("id") );
         obj->delete_temp("giveneck");
         break;
  }
}

void givesurcoat()
{
  int i;
  object me,obj,surcoat;
  me=this_player();
  obj=this_object();
  i=obj->query_temp("givesurcoat");
  if( !me || environment(me) != environment(obj) )
  {
    command("say �x�H" + RANK_D->query_respect(me) + "�H�O�H�H");
    return;
  }
  switch( i )
  {
    case 1:
         say(CYN"�ƫe�D�讳�_�ȱi�A�����a���D�G�n���F�I�y���@�U��C\n"NOR);
         obj->set_temp("givesurcoat",i+1);
         call_out("givesurcoat",2,me);
         break;
    case 2:
         say(CYN"�ƫe�D�觤�b��e�A�}�l�ո˹s��D�D�D�C\n"NOR);
         obj->set_temp("givesurcoat",i+1);
         call_out("givesurcoat",3,me);
         break;
    case 3:
         say(CYN"�ƫe�D�軡�D�G��㤣���A�A���h�ոթʯ�a�C\n"NOR);
         surcoat=new_ob(__DIR__"eq/chain-surcoat");
         surcoat->move(obj);
         command("give surcoat to "+ me->query("id") );
         obj->delete_temp("givesurcoat");
         break;
  }
}

void givewrists()
{
  int i;
  object me,obj,wrists;
  me=this_player();
  obj=this_object();
  i=obj->query_temp("givewrists");
  if( !me || environment(me) != environment(obj) )
  {
    command("say �x�H" + RANK_D->query_respect(me) + "�H�O�H�H");
    return;
  }
  switch( i )
  {
    case 1:
         say(CYN"�ƫe�D�讳�_�ȱi�A�����a���D�G�n���F�I�y���@�U��C\n"NOR);
         obj->set_temp("givewrists",i+1);
         call_out("givewrists",2,me);
         break;
    case 2:
         say(CYN"�ƫe�D�觤�b��e�A�}�l�ո˹s��D�D�D�C\n"NOR);
         obj->set_temp("givewrists",i+1);
         call_out("givewrists",3,me);
         break;
    case 3:
         say(CYN"�ƫe�D�軡�D�G��㤣���A�A���h�ոթʯ�a�C\n"NOR);
         wrists=new_ob(__DIR__"eq/blade-wrists");
         wrists->move(obj);
         command("give wrists to "+ me->query("id") );
         obj->delete_temp("givewrists");
         break;
  }
}
