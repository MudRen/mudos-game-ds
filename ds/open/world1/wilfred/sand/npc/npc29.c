#include <ansi.h>
#include <path.h>
inherit NPC;

int quest();
int game(string game_index);
void eight_mirror();

int move_obj;


int *index3 = ({ 0,0,0,0,0,0,0,0 });    // �� "�R��" �o�q�Ϊ�

void create()
{
  set_name("�Ѿ��ѤH", ({ "astronomy master","master" }) );
  set("gender", "�k��" );
  set("long",@LONG

    ���~�����Ѿ��ѤH�A�õL�u�j�C�F�Z�L�j�|���N�@�C�Ѿ��ѤH
  �@�ʲH�y�W�Q�A�߻P�@�j���A�{�U��L���p�]�l��b�@�_�C�Ѿ�
    �ѤH��q��N�A���Ѿ��A��a�z�A�{�U��s�@�Ǥ��Ѿ��N����
    �A�ǳƦ^�Y�s�s�}�Ѱ}�k�A�^��j�ӫ����L�v���y�Ѿ��l�z��
    �F��A�u�]�R�]�|�~���A���o�A�I�A�ҥH��𥼰ʨ��C

    �������ǡG
    �t�~�½Y�s��񧹾�O�d�U�F�y�Ѿ��l�z�@�ͬ�s�X�����G�C
  �@�b�j�e�����Y�A�s���t�@��A�ٯd�ۤ@�_�}�y�񿪥۰}�z�A�u
  �@�O�a�I���K�A��{�b�٨S���H�˲��ݨ��L�A�۶ǳo�ӥ۰}�O��
  �@���l�ΨӫO�@�Y�ӪF��.......�C

LONG
);      
  set("age",80);
  set("level",8);
  set("race","human");

  set("chat_chance", 10);
  set("chat_msg", ({
(: command("say �@���@�����׹D�]�A���]�a�M��U���Ͳj�C") :),
(: command("say ���ک󶧡A���ک󶧡A�W�����͡A�W�������A�����X�A�`���L��C") :),
(: command("say �����ӷ��A�O�ͨ���A����ͥ|�H�A�|�H���K���C") :),
(: command("say �ΦӤW�̤��׹D�A�ΦӤU�̤��׾��C") :),
"�Ѿ��ѤH���_�b��A�b�a�W�ƥX�@�D�D���H�A���G�b��������C\n",
(: command("think") :),
(: command("say ť���L�W�D�H���ũG�ܼF�`�A�����O����˪��ũO�A�u�Q�ݬݡC") :),
(: command("say �񿪤��Q�|���դj��`�A�U���ܲz�A������v�C") :),
(: command("say �`���D�G�y�ǦӦ��P�A���]�L�P�z�A�p���F�ѥ񿪤��Q�|�������N�A�i�Ѧҡy���g�z�@�ѡC") :),
(: quest :),
}));

  set("talk_reply","�p�G�A�P�ڥ�� <say> �|�o�{�N�Q���쪺������I\n");
  setup();
  set_living_name("astronomy");
  set("mirror_number",1);
  call_out("re_quest",900);
}

void init()
{
  object *obs = all_inventory( environment(this_object()) );
  int i;

  add_action("do_no_ask","ask");

  for(i=0;i<sizeof(obs);i++)
  if( obs[i]->query("victim_name") == "�ѹ�" )
  {
    command("ack");
    message_vision(HIR"\n$N���Ѫ��S�G�y�֡I�쩳�O�֡I�H�������F�ڪ��R�]�I�H�z\n\n"NOR,this_object());
    message_vision(WHT"\n[$N��b�L�R�]�����W�A�h�����n]\n\n"NOR,this_object());
    command("pk");
    command("say �O�A�a�H�I�ǩR�� !!!!");
    for(i=0;i<sizeof(obs);i++)
      if(userp(obs[i])) this_object()->kill_ob(obs[i]);
    break;
  }
}

int do_no_ask()
{
  write("�Х� say <��ͪ��覡> �Ө��o�һݱ����C\n");
  return 1;
}

int quest()
{
  object ob = this_object();

  if(ob->query_temp("pass_quest"))
    message_vision("$N���ۻy�D�G���M�Y�s�s�L�k�˦ۥh�A���`�O���^�v�����P��F�C",ob);
  else command("say �u�O�Ѥ��q�H�@�A�o��Y�s�s����A���D�O�ѷN�R�ڤ��i���]�H�ݨӥ��w�U�s�j�ӡA�����v�����F��A�u���ЧO�H�����~�O�C");
  return 1;
}

void relay_say(object me, string str)
{
  object ob = this_object(), obj;
  string game_index = "no";
  if( !userp(me) ) return;
  if( me == this_object() ) return;

  if(ob->query_temp("game_now"))
  {
    command("say ���٦b�U�ѡA�S�ݨ��ڡH�A���@�U�A���@�U�A�ĨĨĨĨġA�O�n�C");
    return;
  }
  if(ob->query_temp("get_match_now"))
  {
    command("say �ڥ��b���H�R��A�S�ݨ��ڡH�A���@�U�A���@�U�A�ĨĨĨĨġA�O�n�C");
    return;
  }
  if(strsrch(str,"�K����") !=-1)
  {
    command("say �K����N�O�@���K���Ϊ���l�A�W�Y�K�Ӥ���F�������K�Ө��H�C");
    command("say �p�G���F�K����A�K�i�H�ΤR�⪺��k�A��X�}�ѥ񿪥۰}������C");
    command("say ť�����K����H���H�p�G�A����F�K�Ӥ��A�ڥi�H���A���s�զX�_�ӡC");
  }
  if(strsrch(str,"���H") !=-1 || strsrch(str,"�񿪤��Q�|��") !=-1)
    command("say �򥻪��K�Ө��H�O�y���S����[�_���I�z�A�����~���X�ӱo�񿪤��Q�|���A�Y�����ԲӸ����A�аѦҩ��g�@�ѡC");
  if(strsrch(str,"�e��") !=-1 || strsrch(str,"����") !=-1)
    command("say ���׬O�e�ϩάO���ѡA���O�K�����H���򥻨ӷ��A�b���g�����ԲӸ����C");
  if(strsrch(str,"�Y�s�s") !=-1)
    command("say �Y�s�s�b�½Y�s������A���L�o�����j�F�@�����A�o�Q��k�L�h�~��A�o�O�@�D�����C");
  if(strsrch(str,"�U�s�j��") !=-1)
    command("say �U�s�j�Ӽ��äF���j���M�� ... �ڤ��Q���ڪ��p�]�l�A�I�A�o�O��𥼰ʨ����̥D�n��]�C");
  if(strsrch(str,"�񿪥۰}") !=-1)
  {
    command("say �o�i�O���Ѿ��N����ة�@�����_�}�I���Y����p�㦳���A�ש����}�Ѧ��}�I");
    command("cac");
  }
  if(strsrch(str,"�F��") !=-1)
  {
    command("say �A�����O�ڥ��v���F��ܡH���D�A����k���U�ڶܡH�Y�s�s����A�ڵL�k�ʨ�.... ");
    command("sigh");
    command("sob");
  }
  if(strsrch(str,"���s��") !=-1)
  {
    command("flop");
    command("say �Q�s���H�A�@�w�O���F�a�C");
    command("boggle");
  }
  if(strsrch(str,"�]�l") !=-1)
    command("say ��... ���_�ڪ��]�l�A�L�ѬO�R��ۧھǤѾ��N�A���L�Ǧ����ᥲ�M�e���Y�s�s�@���s���A�ӦM�I�F�C");
  if(strsrch(str,"�Ѿ��N") !=-1)
  {
    command("say �Ѿ��N�A�s�Ѫ����A���K���ۥͬۿ����z�A�t�H�e�ϡA���Ѥ��ơA�H�o�񿪤��Q�|���C");
    command("say ���N�L�ҸU���A�Ҥ�������då�A�G��W�[�Ѥ�A�U���a�z�A�L�Ҥ���C");
  }
  if((strsrch(str,"�U") !=-1 && strsrch(str,"��") !=-1) || strsrch(str,"�﫳") !=-1)
  {
    command("hmm");
    command("say �A�]���Ѧ�����ڡH���o�A���o�C");
    command("sau �ӹ﫳�a�A�p��H");
    ob->set_temp("game_now",1);
    write(HIW"[�A�Q��Ѿ��ѤH�U�Ѷ� yes / no�H] "NOR""WHT"(�o�i��|�ᱼ�A���@�������ɶ�)\n"NOR);
    input_to("game",game_index);
    return;
  }
  if(strsrch(str,"���g") !=-1)
    command("say ���g�O�ۥj�H�ӳ̰��j���d�۰�.. ���g�Ҩ������Ѧa�ܲz�A�U���ۥͬ۫g�A�|�ɸ`��A���椣�F���g���ĭz���då�C");
  if(strsrch(str,"�v") !=-1 || strsrch(str,"�Ѿ��l") !=-1)
  {
    command("say �ڪ��v���D�Ѿ��l�O�]�A�L�v��Q�~�e�P�u�A�ڶi�ӷQ�^�Y�s�s������v���F��A���`�O�L�k�F�����@�C");
    command("say �Y�s�s�M�������A�ڮ]�l�~�����o�A�I�C���V���O�A�ڪ��K����򥢦b���F�D�A�ٸH���n�X���A�p���ݨӬO�L�k�i�Q�F�C");
    command("say �K���謰�}�ѥ񿪥۰}�����n�u��A�N��}�Ѱ}�k�A�Y�s�s�٬O���ä@�Ӳ��j�M���A�ܩ�O����M���A�������~�H�D�]�C");
  }
  if(strsrch(str,"�R��") !=-1 )
  {
    if(obj = present("eight mirror",me))
    {
      if(obj->query("get_match_yet"))
      {
        command("say �o�ӤK����v�g�R��L�F�A���v�w�A�p�G�A�n���D���ҩw�����A�h�ݭ쥻���������D�H�a�I");
        return;
      }
      command("say �H�U�t��X�Ӫ����H�A�A�i�n�c�c���O���F�C");
      write(HIC"\n[���ȴ���: �{�b�̦n���X�ȵ��A�N�H�U���H�g�U�ӡA�Ϊ̱z����L"NOR);
      write(HIC"\n           �O�U����k�]��A�]���o�O�}�Ѱ}�k�����n����C]\n\n"NOR);
      obj->set("get_match_yet",1,obj);
      this_player()->start_busy(3);
      ob->set_temp("get_match_now",1);
      call_out("get_match",1,1,obj);
    }
    else command("say �A���ݭn���@�ӧ��㪺�K����A�ڤ~�ର�A�R��C");
  }
  if( (strsrch(str,"��") !=-1 || strsrch(str,"�_") !=-1) && strsrch(str,"�X") !=-1 )
  {
    command("say �� .... �ڬݬ�");
    eight_mirror();
    return;
  }
  return;
}

int accept_object(object who, object ob)
{

  int i,j = 0;
  object *user;
  if(this_object()->query_temp("get_match_now") || this_object()->query_temp("game_now"))
    return notify_fail("�Ѿ��ѤH���G���b���C\n");
  if( ob->query_amount() > 0 )
  {
    message_vision("$N���X"+chinese_number(ob->query_amount())+"�T"+ob->name(1)+"("+ob->query("id")+")��$n�C\n",who,this_object());
    command("say �ڨ���ѤF�A�٭n"+ob->name(1)+"�@ԣ�H���^�h���^�h�C");
    call_out("no_give_money",1,who,ob,ob->query_amount());
    return 1;
  }
  if(ob->query("id") == "wind seal")
  {
    command("oh");
    message_vision("$N�J�Ӫ��ݤF��$n",this_object(),ob);
    command("say ��ӵL�W�D�H���ŬO�o�ˤl����....");
    if(j != 1)
    {
      if(random(4))
      {
        command("thank");
        destruct(ob);
        return 1;
      }
      command("say �A��§�u�����O�A�n�a�A�ڦ^�e�A�@�i�کҼg���ũG�A�A�i�n���[�Q�ΡC");
      switch(random(4))
      {
        case 0 : new(__DIR__"obj/obj5")->move(this_object());
                 break;
        case 1 : new(__DIR__"obj/obj5")->move(this_object());
                 break;
        case 2 : new(__DIR__"obj/obj5")->move(this_object());
                 break;
        case 3 : new(__DIR__"obj/obj5")->move(this_object());
                 break;
      }
    }
    command("give " +who->query("id")+ " tally");
    this_object()->set_temp("item_give",1);
    command("say �A�e�ڪ��šA�ڷ|�n�n���_�Ӫ��C");
    destruct(ob);
    return 1;
  }
  if(ob->query("id") == "tablet")
  {
    if(this_object()->query("pass_quest"))
    {
      command("flop");
      command("say ���v���P��v�g��^�ӤF�A�A�o�O�����a... �u�}�I");
      return notify_fail("");
    }
    destruct(ob);
    command("say �o... �o�O���v���F��... !!!!");
    command("say �v���A�{�ण�v�A�ӵ��z�W�Y�F !!!");
    message_vision(HIW"\n[$N��b�F��e�j��]\n\n"NOR,this_object());
    if(who->query_temp("mission_accept"))
    {
      command("say ���\\�O�کҰU�I���H .....");
      command("say �o��"+RANK_D->query_respect(who)+"�A�P�§A�����U�A���Y��ڳo�����_���A�O���v�d�U�ӵ��ڪ��C");
      command("say �ڧ⥦�e���A�A����A���ҧU�q�C");
      new(__DIR__"obj/obj17")->move(this_object());
      command("give " +who->query("id")+ " pill");
      message_vision(HIW"\n\t[$N�o��_��]\n\n"NOR,who);
    }
    else command("thank");
    this_object()->set_temp("pass_quest",1);
    return 1;
  }
  command("say �ڳo��ѤF�A�٭n"+ob->query("name")+"�@����H���}���}�C");
  write("["+this_object()->name(1)+"��"+ob->name(1)+"�ä��P����]\n");
  return notify_fail("");
}

int re_quest()
{
  object ob = this_object();

  if(query_temp("game_now") || query_temp("get_match_now"))
  {
    remove_call_out("re_quest");
    call_out("re_quest",10);
    return 1;
  }

  ob->delete_temp("pass_quest");
  ob->delete_temp("item_give");
  ob->delete_temp("item_give_who");

  command("say ��A�ɭԤ����F�A����@���ݦb�o�̡A�Ө��F�C");
  random_move();
  switch(random(4))
  {
    case 0 : ob->move("/open/world1/tmr/area/waroom");
             break;
    case 1 : ob->move(WD_PAST+"sand/room7");
             break;
    case 2 : ob->move(WD_PAST+"sand/room22");
             command("say �ڦ^�ӤF�C");
             break;
    case 3 : ob->move(WD_PAST+"sand/room18");
             command("say �o��o��h�H�ڡH�q���A�ͷN�������C");
             break;
  }
  call_out("re_quest",300);
  return 1;
}

int game(string game_index)
{
  if(game_index == "no" || game_index == "n")
  {
    command("say �A�ȤF�ܡH�o�]���ǡA�ڥi�O�ܱj���աC");
    command("cac");
    write(HIB"[�A�n�F�n�Y�A���u�O�Өg���̡A�O�H���������C]\n"NOR);
    this_object()->delete_temp("game_now");
    return 1;
  }
  if(game_index == "yes" || game_index == "y")
  {
    command("flip");
    command("say �n�n�n�A�ڭֶ̧}�l�a�C");
    message_vision("$n�ܧ֪���ѽL�ǳƦn�F�A��O$N�M$n�K�}�l�@���E�P���r���C\n",this_player(),this_object());
    this_player()->start_busy(10);
    call_out("game_start",1,0);
    return 1;
  }
  this_object()->delete_temp("game_now");
  command("say �A���^���ڤ����C�A���A���ک��T�����ЦA���a�C");
  return 1;
}

int game_start(int index)
{
  object me = this_player(), ob = this_object();
  int me_sk, ob_sk;
  me_sk = me->query_skill("chess");
  ob_sk = ob->query_skill("chess");
  me->start_busy(10);
  switch(index)
  {
    case 1 : if(random(2)) message_vision(HIC"[�o����$N���U�A��O$N��F�ӬP�츨�U$N���Ĥ@�l]\n"NOR,me);
               else message_vision(HIC"[$N��o���U���v�Q�A��O$N�ܧ֪��b�P��U�F�@�l]\n"NOR,ob);
             break;
    case 2 : command("hmm");
             write(HIC"�ݨӹ��ëD���P�����A�q�}�l���G���K�i�ݥX�C�w��í�w�A���V�]�۷���T�C\n"NOR);
             break;
    case 3 : message_vision(HIC"�ԡI���@�n�A����S���F�X�l�C\n"NOR,ob);
             break;
    case 4 : command("hoho");
             command("say �ݧڳo�ۡC");
             break;
    case 5 : message_vision(HIC"�v�O�L���F�A�ثe����U�����a�A$N���$n����աA���̥ܮz�������ۡC\n"NOR,me,ob);
             break;
    case 6 : message_vision(HIC"�v�O������դF�A�{�b���西�b�m����x�C\n"NOR,ob);
             command("say ���.... �{�b�o�ˬO...");
             break;
    case 7 : message_vision(HIW"\n\t�ש�U���F�A���G�p��O�H\n\n"NOR,ob);
             break;
    case 8 : if( me_sk > 15 ) call_out("winner",1,1);
               else if( random(me_sk) > 10 ) call_out("winner",1,2);
                      else call_out("winner",1,3);
             break;
  }
  if( index < 8 ) call_out("game_start",7,++index);
  return 1;
}

void winner(int index)
{
  object ob = this_object(), me = this_player();
  if(!random(4)) index = 0;
  switch(index)
  {
    case 1 : message_vision(HIG"\n$N�ܻ������K���ѤF$n�C\n\n"NOR,me,ob);
             command("sigh");
             message_vision("$N�ܱo�N�����D�G $n�A�A�A�Ӯz�F�C�H�Y�����j���C\n",me,ob);
             call_out("mirror",1);
             break;
    case 2 : if(random(2))
             {
               command("inn");
               message_vision(WHT"$N�b���W���ľԤ���A�ש���F$n�C\n"NOR,me,ob);
               command("say �@�ɤj�N��F�A"+RANK_D->query_respect(me)+"��O�����A���L�ڤU���i���|�A��A�F");
               call_out("mirror",1);
             }
             else
             {
               message_vision(CYN"���M$N�O�D�����A���٬O�B��H�աA�̫��F$n�Ƥl�C\n"NOR,me,ob);
               command("spank "+me->query("id"));
               command("say ��A�﫳�u�O�h�֡A��ѧڭ̦A�Ӥj�ԭӤQ���A�������I");
             }
             break;
    case 3 : message_vision(HIR"\n$N�Q$n���o�줣���x�A�ڥ��L�O���$n����աC\n\n"NOR,me,ob);
             command("nomatch "+me->query("id"));
             break;
    default : message_vision(HIW"[����b��a����A�o�{���O�e���⪬�A�A�]���o���P�w�M���C]\n\n"NOR,ob);
              command("shrug");
              break;
  }
  ob->delete_temp("game_now");
  return;
}

int mirror()
{
  object ob = this_object(), me = this_player();
  command("say �A��F�A���Y�ڸӵ��A�Ӥ����y�~�n�C");
  if(ob->query("pass_quest"))
  {
    command("hmm");
    command("say �ڭ쥻�Q�N�y���w�U�s�j�ӡA���^�ڥ��v���F��z�����ȰU�I��A�A���O.....");
    command("say �ڪ��K����H���i���j�v�g���t�@��Z�L�L�h�F�A�ڷQ�A�L���i�H������A���ڨ��^�F��C");
    command("say �u�O��p�A����A�o�I�p�N��ЧA���U�C");
    ob->receive_money(random(10)+1);
    command("give " +me->query("id")+ " coin");
    return 1;
  }
  command("say ���ڨ��W�ٯd�ۤK����䤤�@���H��...");
  command("say ���Y��ڡA��b����K�a�ۧڪ��p�]�l�A�I�Y�s�s�A�ӥB�K����H���{�U�����y����B....");
  command("say �ҥH�A�Ʊ�A�ର�ڥh�@��Y�s�s�A���^�F��A�Ʀ�����A�۷����S�¡C\n");
    new(__DIR__"obj/obj15")->move(ob);
  command("give " +me->query("id")+ " mirror");
  command("say �n�}�ѸU�s�j�Ӫ��Ĥ@�D�u�@���d�y�񿪥۰}�z�A�D�o�ΤK����ӤR�⤣�i�C");
  command("say �h�a�A���A�����K�Ӥ�줧�K����H���A�A�ӧ�ڡA���ɧڷ|���A�N���_�X�����㪺�K����C");
  return 1;
}

void eight_mirror()
{
  int i, j, k;
  object *obs, me = this_player(), ob = this_object();
  object *mirror = allocate(9);
  object war_room;

war_room = load_object(WD_PAST+"sand/room92");
if(war_room->is_war())
{
  command("say �h�§A�����������A���Y�s�s�����ȧڤv�U�I���L�H�F�C");
  command("say ���H�ثe���b�Y�s�s�i�}�@�s�ꪺ��ʡA�z�Ц^�a�C");
  return;
}
  for(i=1;i<9;i++)
  {
    obs = all_inventory(me);
    for(j=0;j<sizeof(obs);j++)
    {
      if(obs[j]->query("accept_side") == i)
      {
        k++;
        mirror[i] = obs[j];
        message_vision(WHT"$N�o�{���W���@�����P��쪺�K����H���A�E�N�����F�X�ӡC\n"NOR,me);
      }
      if(obs[j]->query("accept_side") == i) break;
    }
  }
  if(k != 8)
  {
    command("say ��.... �٬O�S�������K���H��...");
    command("say �����F�A�ӧa ...");
    return;
  }

  for(i=1;i<9;i++)
    destruct(mirror[i]);
  command("say �Ӧn�F�I�I�{�U�K������A�����A���զ^��.... �ݬݧڪ���q�a�C");
  message_vision(HIG"\n[$N�J�Ӫ��N���۸H����A��X�W�h�A���@�|��K�զX�����F]\n\n"NOR,ob);
  new(__DIR__"obj/obj16")->move(me);
  command("give "+me->query("id")+" eight mirror");
  command("say �h�a�A���ڥ��w�M�I���U�s�j�ӡA�åB�Ц^���v���F��A�ڤ@�w�|���������§A�I");

  obs = users();
  for(i=0;i<sizeof(obs);i++)
  {
    if(obs[i]->query_temp("mission_accept") && environment(obs[i]))
    {
      obs[i]->delete_temp("mission_accept");
      message_vision(HIR"$N�N�e�U��$n�����Ȩ����F�I\n"NOR,ob,obs[i]);
      if(environment(obs[i]) != environment(me))
        message_vision(HIR"$n�N�e�U��$N�����Ȩ����F�I\n"NOR,obs[i],ob);
    }
  }

  message("world:world1:vision",NOR""+
  HIW"\t���~�I�I���~�I�I\n\n\t\t"+
  me->name(1)+"�����F�i���F����Х��ȡG�Ѿ��ѤH���ӿաj�I�I\n\n"NOR,users());

  me->set_temp("mission_accept",1);
  return;
}

void no_give_money(object who, object ob, int index)
{
  command("give " +who->query("id")+ " " +index+ " " +ob->query("id"));
}

int get_match(int index1, object obj)
{
  int index4;
  object ob = this_object();
  string temp1, temp2;

  this_player()->start_busy(3);

  switch(index1)
  {
    case 1 : temp1 = "��";
             break;
    case 6 : temp1 = "��";
             break;
    default : temp1 = chinese_number(index1);
  }

  index3[index1] = random(2);
  if(index3[index1] == 1)
    temp2 = HIW"�� ������������"NOR;
  else
    temp2 = HIW""BLK"�� �����@�@����";

  message_vision(NOR""WHT"$N���D�G "+temp1+"����"+temp2+"\n\n"NOR,ob);
  if( index1 % 3 == 0 )
  {
    if(index1 == 3)
    {
      index4 = (index3[1]*1) + (index3[2]*2) + (index3[3]*4);
      obj->set("mirror_set_in",index4);
    }
    else
    {
      index4 = (index3[4]*1) + (index3[5]*2) + (index3[6]*4);
      obj->set("mirror_set_out",index4);
    }

    // �̷� 2 �i��k�Ӻ�, �]�� [�T�����а�] = 1*4 + 1*2 + 1*1 = 7 , �H������
    switch(index4)
    {
      case 0 : temp1 = "�[";
               temp2 = "�a";
               break;
      case 1 : temp1 = "�_";
               temp2 = "�p";
               break;
      case 2 : temp1 = "��";
               temp2 = "��";
               break;
      case 3 : temp1 = "�I";
               temp2 = "�A";
               break;
      case 4 : temp1 = "��";
               temp2 = "�s";
               break;
      case 5 : temp1 = "��";
               temp2 = "��";
               break;
      case 6 : temp1 = "�S";
               temp2 = "��";
               break;
      case 7 : temp1 = "��";
               temp2 = "��";
               break;
    }
    if(index1 == 3) message_vision(HIG"\n$N���D�G �Ѫ�B�G�B�T���o������ ["+temp1+"] �A����"+temp2+"�C\n\n"NOR,ob);
      else  message_vision(HIG"\n$N���D�G �ѥ|�B���B�����o�~���� ["+temp1+"] �A����"+temp2+"�C\n\n"NOR,ob);
  }

  if(index1 != 6)
    call_out("get_match",3,++index1,obj);
  else
  {
    command("sweat");
    command("say �u�ݺ�X�̪�����H�K�����F�A��l�����κ�F�A���t�Y�i�C");
    command("say ���t����k�аѦ�[���g]�@�ѡC");
    ob->delete_temp("get_match_now");
  }

  return 1;
}
