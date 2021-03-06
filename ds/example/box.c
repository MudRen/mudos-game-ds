inherit BOX;
// 要繼承 box

void create()
{
  set_name("基本的寶箱", ({ "default box", "box" }));
  set("long", @LONG
bAsIc BoX.
LONG
  );
  set("value", 1);
  set("unit", "盒");
  set_max_encumbrance(999999); // 最大負重
  set_max_capacity(99); // 最大可容物品數
  set("cover_name", "塑膠蓋\"); // 蓋子的名稱
  set_keys(({ "/example/default_key"})); // 設定可開的鑰匙的目錄+檔名
                                // ex: /example/default_key
                                // 可以用 add_key(string) 來增加
  setup();
  set_cover(4);
// 沒蓋子 2 
// 蓋子是打開 3
// 蓋子被關上 4
// 蓋子被破壞 5
  set_lock(8);
// 沒鎖 6
// 鎖是開的 7
// 鎖是上鎖的 8
// 鎖被破壞 9
}
