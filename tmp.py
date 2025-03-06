# coding=utf-8

import requests
import json

if __name__ == '__main__':
    url = "https://infer-modelarts-cn-southwest-2.modelarts-infer.com/v1/infers/952e4f88-ef93-4398-ae8d-af37f63f0d8e/v1/chat/completions"

    # Send request.
    headers = {
        'Content-Type': 'application/json',
        'Authorization': 'Bearer wwmxSG3baeJzSYmhCtAr7ErMafPRUo8QsOUbn6sKATr60pnfuXc5uyjkRuSNI7k2k6G6xZ5oz6C2NR_nH1aA7w' # 把yourApiKey替换成真实的API Key
    }
    data = {
        "model": "DeepSeek-R1",
        "max_tokens": 2000,
        "messages": [
            {"role": "system", "content": "You are a helpful assistant."},
            {"role": "user", "content": input("请输入您的问题：")}
        ],
        # 是否开启流式推理, 默认为False, 表示不开启流式推理
        "stream": False,
        # 在流式输出时是否展示使用的token数目。只有当stream为True时改参数才会生效。
        # "stream_options": { "include_usage": True },
        # 控制采样随机性的浮点数，值较低时模型更具确定性，值较高时模型更具创造性。"0"表示贪婪取样。默认为1.0。
        "temperature": 0.8
    }
    resp = requests.post(url, headers=headers, data=json.dumps(data), verify=False)

    # Print result.
    print(resp.status_code)
    print(resp.text)
