inherit ROOM;
void create()
{
  set ("short", "����");
  set ("long", @LONG

�o�����s�@�Y�s���A�]�����L�����A�L��a�@�󦹦��\��C

LONG
);
  set("no_recall",1);
  set("no_goto",1);
  setup();
}

int room_effect(object me)
{
  object *env;
  int i;
  env = all_inventory();
  for(i=0;i<sizeof(env);i++)
  {
    if(env[i]->query_temp("fly")) continue;
    if( env[i]->query_temp("float") && random(3) ) continue;
    if(userp(env[i])) continue;
    if(living(env[i]))
    {
      message_vision("$N�@�Ӥ��p�ߡA�Q���檺���y�����F�C\n",env[i]);
      message_vision("\n$N�j�s:�ϩR��! �ϩR��!\n\n",env[i]);
    }
    else message_vision("$N�Q���R���F�C\n",env[i]);
    destruct(env[i]);
    if(!random(3)) break;
  }
  return 1;
}
