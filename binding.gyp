{
  "targets": [
    {
      "target_name": "sword",
      "sources": [ "sword.cc" ],
      'conditions': [
        ['OS=="linux"', {
            'cflags': [
              "-D_FILE_OFFSET_BITS=64", "-D_LARGEFILE_SOURCE"
            ],
            'include_dirs': [
                "/usr/include/sword"
            ],
            'ldflags': [
                '-lsword'
            ]
        }]
      ]
    }
  ]
}
