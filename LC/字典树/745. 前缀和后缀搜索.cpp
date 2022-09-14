//1. 暴力解法
class WordFilter {
public:
    WordFilter(vector<string>& words) {
        for(int i = 0; i < words.size(); ++i)
        {
            string word = words[i];
            int length = word.size();
            for(int prefixLength = 1; prefixLength <= length; ++prefixLength)
            {
                for(int suffixLength = 1; suffixLength <= length; ++suffixLength)
                {
                    string key = word.substr(0, prefixLength) + '&' + word.substr(length - suffixLength);
                    dict[key] = i;
                }
            }
        }
    }
    
    int f(string pref, string suff) {
        string tmp = pref + '&' + suff;	//必须要使用特殊连接字符(不然AC不了)
        return dict.count(tmp) ? dict[tmp] : -1;
    }

    unordered_map<string,int> dict;
};



