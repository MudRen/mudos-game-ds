inherit ROOM;
void create()
{
  set ("short", "�R�߫F");
  set ("long", @LONG
�o�O�@�y�Φˤl弫ت��D�F�A�F���\�F�ˮ�˴ȡA�\�]²��j��
�A�F�l�P��غ��F�C�A���ˤl�A�����٦��@�Ӥp����A�Ѧ��i�ݥX�o
�F�l�D�H�������h�P�C
LONG
);

  set("exits", ([
  "south" : __DIR__"room6",
]));
  set("objects", ([
  __DIR__"npc/npc29" : 1,
]));
  set("no_clean_up", 0);
  set("light",1);
  setup();
}

int room_effect(object me)
{
  switch(random(7))
  {
    case 1 : tell_room(this_object(),"�@�}�D���j�ӡA���صۨC�ӤH���y�U�C\n");
             break;
    case 2 : tell_room(this_object(),"�˪L�b�����������n���ۡA�˸��F�F�@�T�C\n");
             break;
    case 3 : tell_room(this_object(),"�����������M���X�Y�ӡA�H�Y�S��^���̡C\n");
             break;
    default : return 1;
  }
  return 1;
}

void reset()
{
  object npc;
  if(objectp(npc = find_living("astronomy")))
    if(!npc->query_temp("game_now") && !npc->query_temp("get_match_now")) destruct(npc);
      else return;
  ::reset();
  return;
}
