// �s�D�]���O
// Tmr 2007/01/25

#include <ansi.h>

/*
�F�˧Y�ɷs�D
http://www.ettoday.com/rss/opml.xml
*/


// �s�D�Y��
string* titles = 0;
string* getTitles() {
        return titles;
}



string* rss = ({
"/open/news/realtime.rdf",
"/open/news/1.rdf",
"/open/news/2.rdf",
"/open/news/3.rdf",
"/open/news/4.rdf",
"/open/news/5.rdf",
"/open/news/6.rdf",
"/open/news/7.rdf",
"/open/news/8.rdf",
"/open/news/9.rdf",
"/open/news/10.rdf",
});


string read(string file) {
        int i;
    string text, space;
    string news, result = "";
    string *lines;

    if( file_size(file) < 0 ) 
                return "";

    if( !text = read_file(file) )
                return "";

    lines = explode( text, "\n");

    for(i=0;i<sizeof(lines);i++ ) {
                if( sscanf(lines[i], "%s<title>%s</title>", space, news ) != 2) continue;
                if( strlen(news) < 4 ) continue;
                if( strsrch(news, "ETToday") != -1 ) continue;
                  if( strsrch(news, "�F��") != -1 ) continue;
                result += news + "\n";  // �δ���Ÿ��j�}
        }

        return result;
}

void init()
{
        int i;
        string r, result = "";
        for(i=0;i<sizeof(rss);i++) {
                r = read(rss[i]);
                if(r=="") continue;
                 result += r;
        }

        titles = explode( result, "\n");
}

string prefix() {
          return CYN"�i�F�˷s�D�j"NOR;
}


int getSize() {
        return sizeof(titles);
}

string one_title() {
        int idx;
        if(sizeof(titles)<1) return "[����S���s�D]";
        idx = random(sizeof(titles));
        return prefix() + sprintf("%3d/%3d�h ",idx, getSize()) + titles[idx];
}

// �s�����Ҧ����a
void broadcast() {
        message("system", one_title() + "�C\n", users());
}


void create() 
{ 
        seteuid(getuid()); 
                init();
}


