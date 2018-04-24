from django.db import models
from django.contrib.auth.models import User


class PdfPack(models.Model):
    """django model--represents a database. PdfPack.ID is auto init'd"""
    desc = models.CharField(max_length=255, blank=True)
    document = models.FileField(upload_to='documents/')
    uploadTime = models.DateTimeField(auto_now_add=True)
    created_by = models.ForeignKey(User, on_delete=models.CASCADE)
    # note; upload time will upload to $media_root/documents/YYYY/MM/DD
