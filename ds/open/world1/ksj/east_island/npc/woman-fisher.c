inherit NPC;

void create()
{
  set_name("���k",({"woman fisher","fisher"}) );
  set("long",@LONG
�M����J�����A�j�����s���B�j���B��Į���������q��k�ʡA�o
�̥i�H���Υ���˳ƴN����ɶ���b�����A�@�O�۹���H�C
LONG);
  set("race","�H��");
  set("gender", "�k��");  
  set("age",25);
  set("level",17);
  set("attitude","friendly");
  set("chat_chance",5);
  set("chat_msg",({
      "���k�N�ĨӪ���Į��J�y�����U�l���C\n",
      "���k���F�f���A�S��J�����C\n",
     }));
  setup();
  add_money("coin",300);
}

void die()
{
  object ob;
  if( !ob = query_temp("last_damage_from") )
    ob = this_player(1);
  if( !ob ) 
  {
    ::die();
    return;
  }
 
  switch( random(100) )
  {
    case  0..9:
          new(__DIR__"eq/coral-bracelet")->move(this_object());
          break;
    case  10..25:
          new(__DIR__"eq/sea-urchin")->move(this_object());
          break;
    case  50..54:
          new(__DIR__"eq/lobster-wrists")->move(this_object());
          break;
    case  90..99: new(__DIR__"eq/pearl-earring")->move(this_object());
          break;
  }
  ::die();
  return;
}
