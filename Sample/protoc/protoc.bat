set DST_DIR="E:\SampleCode\Google ProtocolBuffer\Sample\protoc"
set SRC_DIR="E:\SampleCode\Google ProtocolBuffer\Sample\protoc"
protoc -I=%SRC_DIR% --cpp_out=%DST_DIR% %SRC_DIR%/addressbook.proto
@pause